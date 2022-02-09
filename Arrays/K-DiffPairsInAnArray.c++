class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int runner = 1;
        int walker = 0;
        int ans = 0;
        while (walker < n && runner < n) {
            if (nums[runner] - nums[walker] == k) {
                walker++;
                runner++;
                ans++;
                while (runner < n && nums[runner] == nums[runner - 1])
                    runner++;
            } else if (nums[runner] - nums[walker] > k) {
                walker++;
                if (runner - walker == 0)
                    runner++;
            } else {
                runner++;
            }
        }
        return ans;
    }
};