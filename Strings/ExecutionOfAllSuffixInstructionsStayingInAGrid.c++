class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size(), j = 0;
        vector<int> ans(m);

        while (j < m) {
            int startRow = startPos[0];
            int startCol = startPos[1];
            int cnt = 0;

            for (int k = j; k < m; k++) {
                if (s[k] == 'L' && startCol - 1 >= 0) {
                    cnt++;
                    startCol--;
                }
                else if (s[k] == 'R' && startCol + 1 < n) {
                    cnt++;
                    startCol++;
                }
                else if (s[k] == 'U' && startRow - 1 >= 0) {
                    cnt++;
                    startRow--;
                }
                else if (s[k] == 'D' && startRow + 1 < n) {
                    cnt++;
                    startRow++;
                } else {
                    break;
                }
            }
            ans[j++] = cnt;
        }
        return ans;
    }
};