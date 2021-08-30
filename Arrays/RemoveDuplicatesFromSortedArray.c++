class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int c = nums.size();
        int n=0;
        for (unsigned int i=0;i<c;i++) {
            if(nums[n] != nums[i]) {
                nums[++n] = nums[i];
            }
        }
        return n!=c?n+1:c;
    }
};