class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        temp={} #declare hashmap
        for i in range(len(nums)):  #for iterating
            num=nums[i] #take another ptr
            if num in temp and i-temp[num]<=k:  #check duplicate condition and if less than k
                return True
            temp[num]=i #place another num in hashmap
        return False
        
        
            
    
            
        