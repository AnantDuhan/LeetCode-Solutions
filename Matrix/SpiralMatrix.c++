#define pb push_back

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        while (top <= bottom && left <= right) {
            
            // traverse from left to right
            for (int i = left; i <= right; i++)
                result.pb(matrix[top][i]);
            top++;

            // traverse down
            for (int i = top; i <= bottom; i++) 
                result.pb(matrix[i][right]);
            right--;

            if (left <= right && bottom >= top) {
                // traverse to right to down
                for (int i = right; i >= left; i--)
                    result.pb(matrix[bottom][i]);
                bottom--;
            }

            if (bottom >= top && left <= right) {
                // traverse upwards
                for (int i = bottom; i >= top; i--)
                    result.pb(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};