class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long dp[200001] = {};
        for (int i = questions.size() - 1; i >= 0; i--) {
            dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
        }
        return dp[0];
    }
};

// 2nd Approach
class Solution {
private:
    long long f(int ind, vector<vector<int>> &questions, vector<long long> &dp) {
        if (ind == questions.size() - 1) {
            return questions[ind][0];
        }
        if (ind >= questions.size()) return 0;
        if (dp[ind] != -1) return dp[ind];

        long long take = questions[ind][0] + f(ind + questions[ind][1] + 1, questions, dp);
        long long notTake = 0 + f(ind + 1, questions, dp);
        return dp[ind] = max(take, notTake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return f(0, questions, dp);
    }
};


// 3rd Approach - Iterative DP
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        int n = questions.size();
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--) {
            long long take = questions[i][0];
            if (i + questions[i][1] + 1 < n)
                take += dp[i + questions[i][1] + 1];

            long long notTake = 0 + dp[i + 1];
            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};