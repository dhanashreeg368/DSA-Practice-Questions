class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left=1                          
        for r in range(1,len(nums)):
            if (nums[r]!=nums[r-1]):
                nums[left]=nums[r]
                left+=1
        return left
