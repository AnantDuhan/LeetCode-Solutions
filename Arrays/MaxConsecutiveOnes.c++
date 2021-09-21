class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), count = 0, mx = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] != 0) {
                count++;
            } else {
                count = 0;
            }
            mx = max(count, mx); 
        }
        return mx;
    }
};