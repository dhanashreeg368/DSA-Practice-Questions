class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n=len(arr)
        left=0
        right=n-1
        while(left<n-1 and arr[left]<arr[left+1]):
            left+=1
        while(right>0 and arr[right]<arr[right-1]):
            right-=1
        if(left>0 and right<n-1 and left==right):
            return True
        else:
            return False
                
        