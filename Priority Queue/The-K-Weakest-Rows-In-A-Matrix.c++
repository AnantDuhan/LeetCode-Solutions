class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        for (int i = mat[0].size() - 1; i >= 0; i--) {
            for (int j = mat.size() - 1; j >= 0; j--) {
                if (mat[j][i] && (i == mat[0].size() - 1 || (mat[j][i + 1] == 0)))
                    ans.push_back(j);
            }
        }

        for (int i = mat.size() - 1; i >= 0; i--) {
            if (mat[i][0] == 0)
                ans.push_back(i);
        }
        return vector<int> (ans.rbegin(), ans.rbegin() + k);
    }
};