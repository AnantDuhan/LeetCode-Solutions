class Solution {
public: 
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i, maxJump = 0;
        if(n==1)
            return 1;
        for(int i=0;i<n;i++) {
            if(maxJump >= i) {
                maxJump = max(maxJump, i+nums[i]);
            }
        }
        return maxJump >= (n-1);
    }
};