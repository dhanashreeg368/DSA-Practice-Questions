class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[amount+1]*(amount+1)
        dp[0]=0 #if we want to calculate amoiunt zero then zero coins - base case 
        
        #using bottom up dp approach
        for i in range(1,amount+1): #from 1 to amount
            for c in coins:
                if (i-c)>=0:
                    dp[i]=min(dp[i], 1+dp[i-c])
        return dp[amount] if dp[amount]!=amount+1 else -1
        