class Solution {
public: 
    int jump(vector<int>& nums) {
        int n = nums.size(), i;
        int jumps = 0, maxReach = 0, currReach = 0;
        for(i=0;i<n-1;i++) {
            maxReach = max(maxReach, i+nums[i]);
            
            if(i == currReach) {
                jumps++;
                currReach = maxReach;
            }
        }
        return jumps;
    }
};