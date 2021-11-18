// Brute Force
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }

        vector<int> ans;
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};

// Hashing
class Solution {
public:
    int arr[100000];
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), k = 0;
        for (auto val : nums)
            arr[val] = 1;

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};