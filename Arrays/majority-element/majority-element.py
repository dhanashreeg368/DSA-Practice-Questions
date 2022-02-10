class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        prev=nums[0]
        cnt=0
        l=(len(nums))//2
        for i in range(len(nums)):
            if (nums[i]==prev):
                cnt+=1
            else:
                cnt=1
                prev=nums[i]
            if (cnt> l):
                return nums[i]
            
            
        