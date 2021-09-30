class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res (nums.size(), 0);
        int p=0,q=1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                res[p] = nums[i];
                p+=2;
            }
            else {
                res[q] = nums[i];
                q+=2;
            }
        }
        return res;
    }
};