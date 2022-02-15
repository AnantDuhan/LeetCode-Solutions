class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                s.erase(nums[i - k - 1]);
            int lo = (nums[i] < INT_MIN + t) ? INT_MIN : nums[i] - t;
            int hi = (nums[i] > INT_MAX - t) ? INT_MAX : nums[i] + t;
            if (s.lower_bound(lo) != s.end() && *(s.lower_bound(lo)) <= hi)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};