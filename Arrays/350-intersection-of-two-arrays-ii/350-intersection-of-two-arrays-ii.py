class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans=[]
        i=0
        j=0
        nums1.sort() #sort both first
        nums2.sort()
        while(i<len(nums1) and j<len(nums2)):
            if (nums1[i]<nums2[j]):
                i+=1
            elif (nums1[i]>nums2[j]):
                j+=1
            else:
                ans.append(nums1[i])
                i+=1
                j+=1
        return ans