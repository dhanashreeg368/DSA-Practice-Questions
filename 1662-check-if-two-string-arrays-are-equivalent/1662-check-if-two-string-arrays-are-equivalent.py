class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        string1=""
        for i in range(len(word1)):
            string1+=word1[i]
        string2=""
        for i in range(len(word2)):
            string2+=word2[i]
        if(string1==string2):
            return True
        else:
            return False
        