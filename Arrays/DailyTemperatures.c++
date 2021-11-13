class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int hot = 0;
        vector<int> ans(n);

        for (int currDay = n - 1; currDay >= 0; currDay--) {
            int currTemp = temperatures[currDay];
            if (currTemp >= hot) {
                hot = currTemp;
                continue;
            }

            int days = 1;
            while (temperatures[currDay + days] <= currTemp) {
                days += ans[currDay + days];
            }
            ans[currDay] = days;
        }
        return ans;
    }
};