class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
	int cur_min_price = prices[0];

	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < prices[i - 1])
		{
			max_profit += max(prices[i -1] - cur_min_price, 0);
			cur_min_price = prices[i];
		}
		else if (i == prices.size() - 1)
		{
			max_profit += max(prices[i] - cur_min_price, 0);
		}
	}

	return max_profit;
    }
};