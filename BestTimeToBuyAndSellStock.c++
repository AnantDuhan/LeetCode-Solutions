class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,n=prices.size(),mini=INT_MAX,res=0;
        for (i=0;i<n;i++) {
            mini=min(mini,prices[i]);
            res=max(res,(prices[i]-mini));
        }
        return res;
    }
};