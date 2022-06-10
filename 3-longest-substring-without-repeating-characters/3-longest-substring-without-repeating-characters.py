class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet=set() #make a set for storing characters 
        l=0
        ans=0
        
        for r in range(len(s)): #iterating through r
            while s[r] in charSet:
                charSet.remove(s[l]) #remove if present already
                l+=1 #move to next index 
            charSet.add(s[r]) #if not present add 
            ans=max(ans, r-l+1) #calculate max length
        return ans
        