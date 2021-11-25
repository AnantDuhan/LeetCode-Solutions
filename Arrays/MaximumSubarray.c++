class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += nums[j];
                //cout<<curr_sum<<endl;
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};