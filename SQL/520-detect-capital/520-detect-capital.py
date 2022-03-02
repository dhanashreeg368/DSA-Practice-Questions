class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if (word.isupper()==True or word.islower()==True or word.istitle()==True):
            return True
        else:
            return False
    
        