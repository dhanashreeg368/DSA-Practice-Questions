class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        e=[]
        o=[]
        for i in range(len(nums)):
            if (nums[i]%2==0):
                e.append(nums[i])
            else:
                o.append(nums[i])
        return e+o
        