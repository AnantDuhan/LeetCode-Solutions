class Solution {
public:
    bool solve(vector<int> &nums, int n, int start, int target, vector<int> &mp, int k) {
        if (start == n)
            return true;
        if (nums[start] > target)
            return false;
        for (int i = 0; i < k; i++) {
            if (mp[i] + nums[start] <= target) {
                mp[i] += nums[start];
                if (solve(nums, n, start + 1, target, mp, k))
                    return true;
                mp[i] -= nums[start];
            }
        }
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            if (a < b)
                return false;
            return true
        });
        for (auto it : nums)
            sum += it;
        if (sum % k != 0)
            return false;
        int target = sum / k;
        vector<int> mp(k, 0);
        return solve(nums, nums.size(), 0, target, mp, k);
    }
};