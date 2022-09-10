class Solution {
public:
	int dp[1001][2][101];
	int helper(vector<int>& prices, int n, int ind, int buy, int cap){
		if(ind==n || cap==0) return 0;
		if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
		int profit;
		if(buy==0){
			profit = max(helper(prices,n,ind+1,0,cap), -prices[ind] + helper(prices,n,ind+1,1,cap));
		}
		if(buy==1){
			profit = max(0+helper(prices,n,ind+1,1,cap),prices[ind] + helper(prices,n,ind+1,0,cap-1));
		}
		return dp[ind][buy][cap] = profit;
	}
	int maxProfit(int k, vector<int>& prices) {
		memset(dp,-1,sizeof(dp));
		return helper(prices,prices.size(),0,0,k);
	}
};