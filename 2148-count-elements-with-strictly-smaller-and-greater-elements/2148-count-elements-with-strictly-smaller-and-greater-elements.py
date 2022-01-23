class Solution:
    def countElements(self, nums: List[int]) -> int:
        nums.sort()
        mmin=nums[0]
        mmax=nums[-1]
        cnt=0
        for i in range(len(nums)):
            if (nums[i]>mmin and nums[i]<mmax):
                cnt+=1
        return cnt
        
                
                
            
            
             
                
            
        