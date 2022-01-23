class Solution {
private:
    void findCombinations(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        int n = arr.size();
        if (ind == n) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick up the element
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombinations(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombinations(ind + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};