class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

        int countZeros;
        int countOnes;

        for (auto &s : strs) {
            countZeros = countOnes = 0;
            for (auto c : s) {
                if (c == '0')
                    countZeros++;
                else if (c == '1')
                    countOnes++;
            }
            for (int i = m; i >= countZeros; i--) {
                for (int j = n; j >= countOnes; j--) {
                    memo[i][j] = max(memo[i][j], memo[i - countZeros][j - countOnes] + 1);
                }
            }
        }
        return memo[m][n];
    }
};