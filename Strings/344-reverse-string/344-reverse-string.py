class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n=len(s) #len of n
        start=0 #start 
        end=n-1 #end
        while(start<=end):
            s[start],s[end]=s[end],s[start] #swap last with first and so on 
            start+=1
            end-=1
        
            
                
                
        