class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int row = m - 1; row >= 0; row--) {
            for (int col1 = 0; col1 < n; col1++) {
                for (int col2 = 0; col2 < n; col2++) {
                    int res = 0;
                    res += grid[row][col1];
                    if (col1 != col2) {
                        res += grid[row][col2];
                    }
                    if (row != m - 1) {
                        int maxi = 0;
                        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
                            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                                if (newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n) {
                                    maxi = max(maxi, dp[row + 1][newCol1][newCol2]);
                                }
                            }
                        }
                        res += maxi;
                    }
                    dp[row][col1][col2] = res;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};