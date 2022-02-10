class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left,right=1,max(piles) #max value of bananas
        res=right #min k value, initially set high
        while left<=right:
            k=(left+right)//2
            hr=0
            for p in piles:
                hr+=ceil(p/k)
            if hr<=h:
                res=min(res,k)
                right=k-1
            else:
                left=k+1
        return res
            
        