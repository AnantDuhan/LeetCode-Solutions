class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), count=0, res = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[j]>nums[i]) {
                    count++;
                }
                res = max(res, nums[j]-nums[i]);
            }
        }
        if(count > 0)
            return res;
        
        return -1;
    }
};