class Solution {
public:
    int dp[201][201] = {};

    int guess(int low, int high) {
        if (low >= high)
            return 0;

        if (dp[low][high])
            return dp[low][high];

        int ans = INT_MAX;

        for (int i = low; i <= high; i++)
            ans = min(ans, max(guess(low, i - 1), guess(i + 1, high)) + i);
        return dp[low][high] = ans;

    }

    int getMoneyAmount(int n) {
        return guess(1, n);
    }
};