class Solution {
public:
    vector<int> dp;
    int helper(int n) {
        if (n < 0) {
            return INT_MAX;
        }
        if (n == 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int mi = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            mi = min(helper(n - i * i), mi);
        }
        dp[n] = mi + 1;
        return mi + 1;
    }

    int numSquares(int n) {
        for (int i = 0; i <= n; i++) {
            dp.push_back(-1);
        }
        return helper(n);
    }
};