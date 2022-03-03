class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #using kadane's algorithm
        if len(nums) == 1:
            return nums[0]
        summ = [0 for i in range(len(nums))]
        summ[0] = nums[0]
        for i in range(1,len(nums)):
            if summ[i-1] < 0:
                summ[i] = nums[i]
            else:
                summ[i] = summ[i-1] + nums[i]
        return max(summ)
            
        