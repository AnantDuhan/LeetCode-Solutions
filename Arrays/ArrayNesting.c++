// Approach 2 - Optimised 
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 1)
                continue;
            int c=0;
            while(vis[i]==0){
                c++;
                vis[i]=1;
                i=nums[i];
            }
            ans=max(ans,c);
        }
        return ans;
    }
};