class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int low = 0;
        int high = n;
        int same = 0;
        for (auto n : nums) {
            if (n < pivot)
                ++same;
            if (n > pivot)
                --high;
        }
        vector<int> res(n);
        for (auto n : nums) {
            if (n < pivot)
                res[low++] = n;
            else if (n == pivot)
                res[same++] = n;
            else
                res[high++] = n;
        }
        return res;
    }
};