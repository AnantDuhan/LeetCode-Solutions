class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(auto n: nums) {
            n = abs(n) - 1;
            if(nums[n]>0)
                nums[n] = -nums[n];
            else
                res.push_back(n+1);
        }
        return res;
    }
};