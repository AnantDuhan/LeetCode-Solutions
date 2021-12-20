// Sort + 2 Traversals
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;

        int diff = INT_MAX;

        for (int i = 0; i < arr.size() - 1; ++i) {
            diff = min(diff, arr[i + 1] - arr[i]);
        }

        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == diff)
                res.push_back({arr[i], arr[i + 1]});
        }
        return res;
    }
};

// Sort + 1 Traversal
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;

        int minPairDiff = INT_MAX;

        for (int i = 0; i < arr.size() - 1; ++i) {

            int currPairDiff = arr[i + 1] - arr[i];

            if (currPairDiff == minPairDiff)
            {
                res.push_back({arr[i], arr[i + 1]});
            }
            else if (currPairDiff < minPairDiff)
            {
                res = {};
                res.push_back({arr[i], arr[i + 1]});
                minPairDiff = currPairDiff;
            }
        }
        return res;
    }
};