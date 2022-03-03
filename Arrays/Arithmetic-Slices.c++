class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0, cnt = 0;
        int n = nums.size();

        if (n < 3)
            return 0;

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                ++dp;
            else
                dp = 0;
            cnt += dp;
        }
        return cnt;
    }
};