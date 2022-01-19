class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        long long ans = 0;
        while (i < n) {
            long long len = 1;
            while (i + 1 < n && (prices[i + 1] - prices[i] == -1)) {
                i++;
                len++;
            }
            ans += (len * (len + 1) / 2);
            i++;
        }
        return ans;
    }
};