class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        if(binary_search(nums.begin(), nums.end(), target)) {
            int index = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            return index;
        } else {
            for(;i<nums.size();i++)
                if(nums[i]>target)
                    return i;
        }
        return i;
    }
};