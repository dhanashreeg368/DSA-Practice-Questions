class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s=[str(i) for i in digits] #converting int list to string list 
        res=int("".join(s)) #joining the string
        ans_int=res+1
        ans = list(map(int, str(ans_int)))
        return ans