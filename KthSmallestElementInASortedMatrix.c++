class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long long int n = matrix.size();
        long long int i,j;
        vector<int>s;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                long long int a = matrix[i][j];
                s.push_back(a);
            }
        }
        sort(s.begin(), s.end());
        return s[k-1];
    }
};