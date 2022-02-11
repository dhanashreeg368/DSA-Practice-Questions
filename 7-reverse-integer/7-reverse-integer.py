class Solution:
    def reverse(self, x: int) -> int:
        isNegative=False 
        if x<0:
            isNegative=True
            x=-x
        rev=0
        while x:
            rev=rev*10 + x%10 #calcualte reverse 
            x//=10
        if (rev>=2**31-1 or rev <=-2**31): #to check range
            return 0
        if isNegative==True:
            return -rev
        else:
            return rev