class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        prev=nums[0]
        cnt=1
        for i in range(1,len(nums)):
            if (prev==nums[i]):
                cnt+=1
                if (cnt>=2):
                    return True 
            else:
                prev=nums[i]
                cnt=1
        return False


            
        