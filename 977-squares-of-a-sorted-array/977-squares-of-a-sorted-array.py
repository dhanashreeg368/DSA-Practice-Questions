class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums[i]=nums[i]*nums[i]
        nums.sort()
        return nums
    
    #can be also solved using 2 ptrs algorithm using O(n) time
    #left=0 , right=last index, index=last index
    #if nums[left]>nums[right]:
    #   result[index]=nums[left]*nums[left]
    #   left+=1
    #else:
    #   result[index]=nums[right]*nums[right]
    #   right-=1
    #index-=1
    #return nums
            
        