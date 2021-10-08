class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        for (int lo = 0, hi = m*n; lo < hi; ) {
            int mid = lo + (hi - lo)/2, i = mid/n, j = mid%n; 
            if (matrix[i][j] < target) 
                lo = mid + 1;
            else if (matrix[i][j] == target) 
                return true; 
            else 
                hi = mid; 
        }
        return false;
    }
};