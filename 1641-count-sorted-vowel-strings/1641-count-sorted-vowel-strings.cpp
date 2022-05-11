class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][6];
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=5;j++)
            {
                    dp[i][j]=(i>1?dp[i-1][j]:1)+dp[i][j-1];                         
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cout<<dp[i][j]<<endl;
            }
        }
        return dp[n][5];
    }
};