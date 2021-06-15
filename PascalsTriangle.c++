class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);
    
    for (int i = 0; i < numRows; i++) {
        switch (i) {
            case 0:
                res[i] = {1};
                break;
            case 1:
                res[i] = {1,1};
            default:
                res[i] = vector<int>(i + 1);
                res[i][0] = 1;
                int a = res[i - 1][0], b = res[i - 1][1];
                for (int j = 1; j < i; j++) {
                    res[i][j] = a + b;
                    a = b;
                    b = res[i - 1][j + 1];
                }
                res[i][i] = 1;
                break;
        }
    }
    
    return res;
    }
};