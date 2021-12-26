// Brute Force
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = -1, r = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (l == -1)
                    l = i;
                r = i;
            }
        }
        return {l, r};
    }
};

// Binary Search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target + 1) - 1;
        if (idx1 < nums.size() && nums[idx1] == target)
            return {idx1, idx2};
        else
            return { -1, -1};
    }

    int lower_bound(vector<int> nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// Binary Search + STL
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>pos;
        if (!binary_search(nums.begin(), nums.end(), target))
        {
            pos.push_back(-1);
            pos.push_back(-1);
        }
        else {
            pos.push_back(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
            pos.push_back(upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1);
        }
        return pos;
    }
};