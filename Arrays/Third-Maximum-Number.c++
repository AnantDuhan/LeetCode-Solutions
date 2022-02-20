class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), cnt = 1;
        if (n < 3)
            return nums[n - 1];

        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                cnt++;
            if (cnt == 3)
                return nums[i];
        }
        return nums[0];
    }
};