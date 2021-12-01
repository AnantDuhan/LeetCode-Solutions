class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(nums.size(), -1);

        return HouseBroken(nums, 0, dp);
    }

    int HouseBroken(vector<int> nums, int start, vector<int>& dp) {
        if (start >= nums.size())
            return 0;
        if (dp[start] > -1)
            return dp[start];
        return dp[start] = max(nums[start] + HouseBroken(nums, start + 2, dp), HouseBroken(nums, start + 1, dp));
    }
};