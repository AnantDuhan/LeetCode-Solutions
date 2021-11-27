class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> Begin(n);
        vector<int> Last(n);
        Begin[0] = 1;
        Last[0] = 1;

        for (int i = 1; i < n; i++) {
            Begin[i] = Begin[i - 1] * nums[i - 1];
            Last[i] = Last[i - 1] * nums[n - i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = Begin[i] * Last[n - 1 - i];
        }
        return res;
    }
};

// Improved Code
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int Begin = 1;
        int Last = 1;

        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {
            res[i] *= Begin;
            Begin *= nums[i];
            res[n - 1 - i] *= Last;
            Last *= nums[n - 1 - i];
        }
        return res;
    }
};