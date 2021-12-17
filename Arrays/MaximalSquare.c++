// Brute Force
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    int sqLen = 1;
                    bool flag = true;
                    while (sqLen + i < m and sqLen + j < n and flag) {
                        for (int k = j; k < sqLen + j; k++) {
                            if (matrix[i + sqLen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqLen + i; k++) {
                            if (matrix[k][j + sqLen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            sqLen++;
                    }
                    if (maxLen < sqLen)
                        maxLen = sqLen;
                }
            }
        }
        return maxLen * maxLen;
    }
};

// Dynamic Programming
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        if (matrix.empty())
            return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                maxLen = max(dp[i][j], maxLen);
            }
        }
        return maxLen * maxLen;
    }
};

// Optimal Dynamic Programming
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n + 1);
        int maxLen = 0, prev = 0;
        if (matrix.empty())
            return 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxLen = max(maxLen, dp[j]);
                } else
                    dp[j] = 0;
                prev = temp;
            }
        }
        return maxLen * maxLen;
    }
};