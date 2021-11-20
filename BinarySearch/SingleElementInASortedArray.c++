class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), mid, num;
        int low = 0, high = n - 1;
        
        if(n == 1)
            return nums[0];
        
        while(low < high) {
            mid = low + (high - low) / 2;
            num = (mid % 2 == 0) ? mid + 1 : mid - 1;
            if(nums[mid] == nums[num]) 
                low = mid + 1;
            else 
                high = mid;
        }
        return nums[low];
    }
};
