// Top Down DP

class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> memo;

    long totalWays(int unpicked, int undelivered) {
        if (unpicked == 0 and undelivered == 0)
            return 1;
        if (unpicked < 0 or undelivered < 0 or undelivered < unpicked)
            return 0;
        if (memo[unpicked][undelivered])
            return memo[unpicked][undelivered];
        long ans = 0;

        // all choices for picking up an order
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        ans %= mod;

        // all choices for delivering a picked order
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        ans %= mod;

        return memo[unpicked][undelivered] = ans;
    }
public:
    int countOrders(int n) {
        memo = vector<vector<int>> (n + 1, vector<int> (n + 1, 0));
        return totalWays(n , n);
    }
};

// Bottom Up DP

class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n) {
        vector<vector<long>> dp(n + 1, vector<long> (n + 1, 0));

        for (int unpicked = 0; unpicked <= n; unpicked++) {
            for (int undelivered = unpicked; undelivered <= n; undelivered++) {
                if (unpicked == 0 and undelivered == 0) {
                    dp[unpicked][undelivered] = 1;
                    continue;
                }

                if (unpicked > 0)
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
                dp[unpicked][undelivered] %= mod;

                if (undelivered > unpicked)
                    dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                dp[unpicked][undelivered] %= mod;
            }
        }
        return dp[n][n];
    }
};

// Permutation(Math)

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans *= i;

            ans *= (2 * i - 1);
            ans %= mod;
        }
        return ans;
    }
};
