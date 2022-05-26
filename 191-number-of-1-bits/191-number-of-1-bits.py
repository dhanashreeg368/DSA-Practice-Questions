class Solution:
    def hammingWeight(self, n: int) -> int:
        string=str(bin(n))
        cnt=0
        for i in string:
            if i=='1':
                cnt+=1
        return cnt
        