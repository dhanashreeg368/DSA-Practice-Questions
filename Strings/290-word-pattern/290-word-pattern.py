class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        dic = dict()
        lis = s.split(' ')
        if len(lis) != len(pattern):
            return False
        if len(set(lis)) != len(set(pattern)):
            return False
        for i in range(len(lis)):
            if pattern[i] not in dic:
                dic[pattern[i]] = lis[i]
            elif pattern[i] in dic and dic[pattern[i]] != lis[i]:
                return False
        
        return True
            
        
            
        
        