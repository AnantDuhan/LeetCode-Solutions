class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        l=len(nums)
        nums.sort()
        Min=999999999999999
        for i in range((l-k)+1):
            mx=nums[i+k-1]
            mn=nums[i]
            diff=mx-mn
            Min=min(diff,Min)
        return(Min)