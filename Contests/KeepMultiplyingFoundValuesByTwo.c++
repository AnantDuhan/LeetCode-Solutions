class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        if (n == 1 && nums[0] == original) {
            return 2 * original;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (original == nums[i]) {
                original = 2 * original;
            } else {
                continue;
            }
        }
        return original;
    }
};