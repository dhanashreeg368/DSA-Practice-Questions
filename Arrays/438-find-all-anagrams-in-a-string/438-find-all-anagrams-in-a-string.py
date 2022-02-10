class Solution:
    from collections import Counter
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        pCnt = Counter(p)
        sCnt = Counter(s[:len(p)-1])
        for i in range(len(p)-1,len(s)):
            sCnt[s[i]] += 1   # include a new char in the window
            if sCnt == pCnt:    # This step is O(1), since there are at most 26 English letters 
                ans.append(i-len(p)+1)   # append the starting index
            sCnt[s[i-len(p)+1]] -= 1   # decrease the count of oldest char in the window
            if sCnt[s[i-len(p)+1]] == 0:
                del sCnt[s[i-len(p)+1]]   # remove the count if it is 0
        return ans
        