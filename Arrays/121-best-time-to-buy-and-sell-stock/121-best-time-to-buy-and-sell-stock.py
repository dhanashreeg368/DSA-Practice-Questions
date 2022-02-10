class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        else:
            res=0
            min_val=prices[0]
            for i in range(1,len(prices)):
                res=max(res,prices[i]-min_val)
                min_val=min(min_val,prices[i])
            return res
        