class Solution {
private:
    bool isArithmetic(vector<int>& nums, int start, int end) {
        if (start >= end)
            return true;

        vector<int> arr = nums;
        sort(arr.begin() + start, arr.begin() + end + 1);
        int diff = arr[start + 1] - arr[start];
        for (int i = start + 1; i <= end - 1; i++) {
            if (arr[i + 1] - arr[i] != diff)
                return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), false);

        for (int i = 0; i < l.size(); i++) {
            if (isArithmetic(nums, l[i], r[i]))
                ans[i] = true;
        }
        return ans;
    }
};