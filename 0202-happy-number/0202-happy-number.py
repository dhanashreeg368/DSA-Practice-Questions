class Solution:
    def isHappy(self, n: int) -> bool:
        set_of_no=set()
        while n!=1: 
            n=sum([int(i)**2 for i in str(n)]) #squaring the digits of no
            if n in set_of_no: #checking whether the no is present in set_of_no
                return False #if present that means it will repeat the terms(or in endless loop)
            set_of_no.add(n) #if not present add it to set
        return True
        