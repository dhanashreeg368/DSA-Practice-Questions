class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n=len(nums) #find length
        numbers=set(range(1,n+1)) #make set of numbers 
        for i in nums: #iterate in nums
            if i in numbers: 
                numbers.remove(i)
        return list(numbers)
        
            
        