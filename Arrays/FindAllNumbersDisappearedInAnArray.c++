class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n;
        for(int i=0;i<nums.size();i++) {
            int n = nums[i];
            if(nums[i]<0)
                n = nums[i]*-1;
            if(nums[n-1]>0)
                nums[n-1] *= -1;
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > 0) 
                ans.push_back(i+1);
        }
        return ans;
    }
};