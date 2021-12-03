// Brute Force - O(N^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        for (int i = 0; i < n; i++) {
            int prod = nums[i];
            for (int j = i + 1; j < n; j++) {
                res = max(res, prod);
                prod *= nums[j];
            }
            res = max(res, prod);
        }
        return res;
    }
};

// Optimal Solution - Kadane Algorithm - O(N)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxNum = nums[0];
        int minNum = nums[0];
        int maxSoFar = nums[0];
        for (int i = 1; i < n; i++) {
            int tmp = max({nums[i], nums[i]*maxNum, nums[i]*minNum});
            minNum = min({nums[i], nums[i]*maxNum, nums[i]*minNum});
            maxNum = tmp;
            maxSoFar = max(maxSoFar, maxNum);
        }
        return maxSoFar;
    }
};