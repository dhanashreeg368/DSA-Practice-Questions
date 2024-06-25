class Solution:
    def isPalindrome(self, x: int) -> bool:
        num=str(x)
        i=0
        j=len(num)
        while (i<=j):
            if(num[i]==num[j-1]):
                i+=1
                j-=1
            else:
                return False
        return True
            
        