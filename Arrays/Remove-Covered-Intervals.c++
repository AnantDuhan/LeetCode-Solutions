class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int left = -1, right = -1, res = 0;
        sort(intervals.begin(), intervals.end());

        for (vector<int> it : intervals) {
            if (it[0] > left and it[1] > right) {
                left = it[0];
                res++;
            }
            right = max(right, it[1]);
        }
        return res;
    }
};