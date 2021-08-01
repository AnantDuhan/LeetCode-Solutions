class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int res = INT_MIN, run = 0;
    for (auto n : nums) {
        run = max(n, n + run);
        res = max(res, run);
    }
    return res;
    }
};