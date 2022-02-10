class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        #example
        #     1 7 3 6 5 6 
        #indx 0 1 2 3 4 5 
        # l_sum=0
        # r_sum=28
        #suppose at ind 3 
        #do 17 - 6 =11 left sum 
        #r sum 5+6= 11 
        # if equal return i
        l_sum=0 #initializing left sum to zero
        r_sum=sum(nums) #it is the sum of all right values 
        for i in range(len(nums)):
            l_sum+=nums[i] #incrementing nums[i] in l_sum
            r_sum-=nums[i] #decrementing nums[i] from r_sum
            if ((l_sum - nums[i]) == r_sum):
                return i
        return -1
            
        
            

        