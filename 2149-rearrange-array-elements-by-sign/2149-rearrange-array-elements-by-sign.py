class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos=[]
        neg=[]
        
        for i in range(len(nums)):
            if (nums[i]>0):
                pos.append(nums[i])
            else:
                neg.append(nums[i])
        i=0
        j=0
        k=0
        li= [0] *(len(pos) + len(neg))
        while(i<len(pos) and j<len(neg)):
            li[k] = pos[i]
            i += 1
            k += 1
            
            li[k] = neg[j]
            j += 1
            k += 1
        while (i < len(pos)) :
            li[k] = pos[i]
            i += 1
            k += 1
        while (j < len(neg)) :
            li[k] = neg[j]
            k += 1
            j += 1
        return li
        
            
                    
            
            
            

        