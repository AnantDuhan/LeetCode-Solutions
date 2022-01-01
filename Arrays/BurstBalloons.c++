// Brute Force - O(N^3)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));

        for (int i = 0; i <= n; i++) {
            for (int start = 1; start <= n - i + 1; ++start) {
                int end = start + i - 1;

                int bestCoins = 0;

                for (int j = start; j <= end; ++j) {
                    int coins = rangeValues[start][j - 1] + rangeValues[j + 1][end];
                    coins += nums[start - 1] * nums[j] * nums[end + 1];
                    if (coins > bestCoins)
                        bestCoins = coins;
                }
                rangeValues[start][end] = bestCoins;
            }
        }
        return rangeValues[1][n];
    }
};