class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        num=set(nums)
        num=list(num)
        num.sort(reverse=True) 
        if (len(num)<3):
            return num[0]
        else:
            return num[2]
       
        