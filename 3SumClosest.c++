class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));    
        int minDiff = INT_MAX;
        int sum     = 0;
        for(int i = 0; i<n-2; i++) 
        {
            int l = i+1, r = n-1;    
            while(l < r) 
            {
                int temp = nums[i] + nums[l] + nums[r];
                int diff = abs(target-temp);    
                if(diff < minDiff) 
                {
                    minDiff = diff;
                    sum     = temp;
                    if(minDiff == 0) return sum;
                }
                if(temp < target) l++;
                else r--;
            }
        }
        return sum;
    }
};