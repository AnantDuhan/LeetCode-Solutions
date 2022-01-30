class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int>l(n, 0), r(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i == 0 && nums[i] == 0)
                l[i] = 1;

            if (i > 0) {
                if (nums[i] == 0)
                    l[i] = l[i - 1] + 1;
                else
                    l[i] = l[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 && nums[i] == 1)
                r[i] = 1;

            if (i < n - 1 && i >= 0 ) {
                if (nums[i] == 1)
                    r[i] = r[i + 1] + 1;
                else
                    r[i] = r[i + 1];
            }
        }
        int x = INT_MIN;
        map<int, vector<int>>mp;
        mp[r[0]].push_back(0);
        mp[l[n - 1]].push_back(n);
        x = max(x, r[0]);
        x = max(x, l[n - 1]);
        for (int i = 0; i < n - 1; i++) {
            int s = l[i] + r[i + 1];
            mp[s].push_back(i + 1);
            x = max(s, x);
        }
        vector<int>ans;
        for (auto m : mp[x])
            ans.push_back(m);

        return ans;
    }
};