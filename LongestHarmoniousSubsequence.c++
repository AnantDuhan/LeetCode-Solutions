class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res=0;   
     unordered_map<int,int> umap;
     for(int i=0;i<nums.size();i++)
         umap[nums[i]]++;
     for(auto p:umap)
     {
      if(umap.find(p.first+1) != umap.end())    
          res=max(res,p.second + umap[p.first+1]);
     }
     return res; 
    }
};