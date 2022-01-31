// TC - O(M.N), SC - O(1);
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (vector<int>& account : accounts) {
            int curr = 0;
            for (int money : account) {
                curr += money;
            }
            maxWealth = max(maxWealth, curr);
        }
        return maxWealth;
    }
};