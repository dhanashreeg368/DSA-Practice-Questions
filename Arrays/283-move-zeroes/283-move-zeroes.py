class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #using 2 pts algorithm
        l=0 #taking left ptr
        r=0 #taking right ptr
        n=len(nums)
        if (n==0 or n==1):
            return 
        for r in range(n): #iterate till r reaches end 
            if (nums[r]==0): #if value at idx r is zero inc r 
                r+=1
            else: #else swap the 2 values
                nums[l],nums[r]=nums[r],nums[l]
                l+=1
                r+=1
            
        