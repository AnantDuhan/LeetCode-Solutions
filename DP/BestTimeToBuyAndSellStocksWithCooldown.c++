class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<int>nostock(n, 0), inhand(n, 0), sold(n, 0);
        inhand[0] = -prices[0]; //// we have bought a stock
        for (int i = 1; i < n; i++) {
            nostock[i] = max(nostock[i - 1], sold[i - 1]);
            inhand[i] = max(inhand[i - 1], nostock[i - 1] - prices[i]);
            sold[i] = inhand[i - 1] + prices[i];
        }
        int x = max(nostock[n - 1], sold[n - 1]);
        return max(x, inhand[n - 1]);
    }
};