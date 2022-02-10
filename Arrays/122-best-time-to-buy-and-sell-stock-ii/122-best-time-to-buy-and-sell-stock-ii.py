class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #everyday there are 3 options buy,sell and do nothing
        #Approach - We will subtract new i+1 value with i, and always keep the maximum value
        #example - 7,1,5,3,6,4
        # 1-7=-6 max(-6,0)=0
        # 5-1=4  max(4,0)=4
        # 3-5=-2 max(-2,0)=0
        # 6-3=3  max(3,0)=3
        # 4-6=-2 max(-2,0)=0
        #max_profit= 0+4+0+3+0=7
        
        max_profit=0
        for i in range(len(prices)-1):
            max_profit+=max(prices[i+1]-prices[i],0)
        return max_profit
        