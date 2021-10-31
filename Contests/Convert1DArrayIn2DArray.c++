// Brute Force

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (m * n != original.size())
            return ans;
        // int idx = 0;
        // for(int i=0;i<m;i++) {
        //     vector<int> col;
        //     for(int j=0;j<n;j++) {
        //         col.push_back(original[idx++]);
        //     }
        //     ans.push_back(col);
        // }

        vector<vector<int>> ans1(m, vector<int>(n, 0));
        for (int i = 0; i < original.size(); i++) {
            ans1[i / n][i % n] = original[i];
        }
        return ans1;
    }
};