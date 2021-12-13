class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto s : nums)
            sum += s;

        if (sum % 2)
            return false;

        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (auto s : nums) {
            for (int i = sum; i >= s; i--) {
                dp[i] = dp[i] || dp[i - s];
            }
        }
        return dp[sum];
    }
};