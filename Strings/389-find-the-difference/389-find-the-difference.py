class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s=list(s)
        t=list(t)
        for i in s:
            t.remove(i)
        return t[0]
            
        
        