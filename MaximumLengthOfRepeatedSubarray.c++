class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = nums1[i-1] == nums2[j-1]? 1 + dp[i-1][j-1] : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};