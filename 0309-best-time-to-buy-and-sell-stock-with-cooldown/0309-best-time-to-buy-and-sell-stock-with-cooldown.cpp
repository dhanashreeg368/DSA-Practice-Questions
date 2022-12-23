class Solution {
public:
    /*
    1. 3 options a day buy sell or leave
    2. If bought , then only sell or leave (until you sell)
    3. If sold , then only buy or leave (until you sell)
    4. If left , then buy or sell (if you have any)
    */
    int dfs(int i , int turn , vector<int>& prices , vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        // 0 for buy
        // 1 for sell 
        // 2 for last day sold
        if(dp[i][turn] != -1){
            return dp[i][turn];
        }
        if(turn == 0){
            return dp[i][turn] = max(-prices[i] + dfs(i + 1 , 1 , prices , dp) , dfs(i + 1 , 0 , prices , dp));
        }
        else if(turn == 1){
            return dp[i][turn] = max(prices[i] + dfs(i + 1 , 2 , prices , dp) , dfs(i + 1 , 1 , prices , dp));
        }
        else{
            return dp[i][turn] = dfs(i + 1 , 0 , prices , dp);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1 , vector<int>(3 , -1));
        return dfs(0 , 0 , prices , dp);
    }
};