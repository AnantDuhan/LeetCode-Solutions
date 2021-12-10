// Brute Force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;
        while (k--) {
            int temp = nums[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                nums[i + 1] = nums[i];
            }
            nums[0] = temp;
        }
    }
};

// More Optimised
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[(i + k) % n] = nums[i];
        }
        nums = res;
    }
};

// Optimal Solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
