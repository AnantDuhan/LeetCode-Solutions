class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                string x = nums[i] + nums[j];
                if (x == target)
                    count++;
            }
        }
        return count;
    }
};