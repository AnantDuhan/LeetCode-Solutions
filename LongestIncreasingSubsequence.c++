class Solution {
public:
    
    //Approach 1: Time Complexity = O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int lis[n];
        memset(lis, 0, sizeof(lis));
        int max_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i == 0)
                lis[i] = 1;
            else{
                for(int j = 0; j < i; j++){
                    if(nums[j] < nums[i])
                        lis[i] = max(lis[i], lis[j] + 1);
                    else
                        lis[i] = max(lis[i], 1);    
                }
            }
            max_1 = max(max_1, lis[i]);
        }
        return max_1;
    }
};

class Solution {
public:
    
    //Approach 2: Time Complexity = O(n * log(n))
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v;
        int max_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i == 0)
                v.push_back(nums[i]);
            else{
                auto x = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                if(x >= v.size())
                    v.push_back(nums[i]);
                else
                v[x] = nums[i];
            }    
        }
        return v.size();
    }
};