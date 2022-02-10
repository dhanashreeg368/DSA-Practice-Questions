class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        l_sum=0
        r_sum=sum(nums)
        for i in range(len(nums)):
            l_sum+=nums[i]
            r_sum-=nums[i]
            if ((l_sum - nums[i])==r_sum):
                return i
        return -1
        