class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int i, n = nums.size();
        int mxp[n], mns[n];
        mxp[0] = nums[0];
        mns[n-1] = nums[n-1];
        
        for(i=1;i<n;i++)
            mxp[i] = max(mxp[i-1], nums[i]);
        
        for(i=n-2;i>=0;i--)
            mns[i] = min(mns[i+1], nums[i]);
        
        for(i=0;i<n-1;i++)
            if(mxp[i]<=mns[i+1])
                return i+1;
        
        return n;
    }
};