class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort() #sort the array first
        if nums[0] != 0:
            return 0
        if nums[-1] != len(nums):
            return len(nums)
        for i in range(1, len(nums)): #traverse the array
            exp_val=nums[i-1]+1 #exp_val = prev_val +1
            if (nums[i]!=exp_val): #if not equal then return
                return exp_val
                
                
        

        