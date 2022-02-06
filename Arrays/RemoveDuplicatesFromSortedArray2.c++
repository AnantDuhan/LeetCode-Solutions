class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;

        int ind = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[ind - 2]) {
                nums[ind] = nums[i];
                ind++;
            }
        }
        return ind;
    }
};