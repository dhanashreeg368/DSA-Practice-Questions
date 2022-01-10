class Solution:
    def fib(self, n: int) -> int:
        f1=0 #initial term
        f2=1 #term 2
        cnt=1 #cnt=1
        if (n==0):
            return f1
        if (n==1):
            return f2
        else:
            while cnt<n:
                fn=f1+f2 #next term is sum of first 2 terms
                f1=f2    #exchanging f1,f2 and fn
                f2=fn
                cnt+=1
        return fn
                
           
        
        