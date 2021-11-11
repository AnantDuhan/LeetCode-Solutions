class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        while (k > 0) {
            k--;
            nums[0] = -nums[0];
            sort(nums.begin(), nums.end());
        }
        for (int i = 0; i < n; i++) {
            res += nums[i];
        }
        return res;
    }
};