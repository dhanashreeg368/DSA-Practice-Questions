class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        #approach is to iterate in the array add next with previous
        #input 1 2 3 4 
        #output1 3 6 10
        for i in range(len(nums)-1):
            nums[i+1]=nums[i]+nums[i+1]
        return nums