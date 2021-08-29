class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        const int N = tasks.size();
        vector<int> dp(1 << N, 1000);
        dp[0] = 0;
        for (int s = 1; s < 1 << N; s++) {
            int req = 0;
            for (int i = 0; i < N; i++) if ((s >> i) & 1) req += tasks[i];
            if (req <= sessionTime) dp[s] = 1;
            for (int t = s; ; t = (t - 1) & s) {
                if (dp[s] > dp[t] + dp[s - t]) dp[s] = dp[t] + dp[s - t];
                if (t == 0) break;
            }
        }
        return dp.back();
    }
};