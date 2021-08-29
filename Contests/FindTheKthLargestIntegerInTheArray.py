class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        for i in range(len(nums)):
            nums[i]=int(nums[i])
        nums.sort()
        set(nums)
        return(str(nums[len(nums)-k]))