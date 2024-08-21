class Solution {
public:

string removeduplicate(string &s)
{
    string uniqueChars;
    int i = 0;
    while(i < s.size())
    {
        char currentChar = s[i];
        uniqueChars += currentChar;

        while(i < s.size() && s[i] == currentChar)
        i++;
    }
    return uniqueChars;
}

int solve(int i,int j,string& s,vector<vector<int>> &dp)
{
    if(i > j)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int minTurns = 1 + solve(i+1,j,s,dp);

    for(int k = i+1;k <= j;k++)
    {
        if(s[i] == s[k])
        minTurns = min(minTurns,solve(i,k-1,s,dp)+solve(k+1,j,s,dp));
    }

    return dp[i][j] = minTurns;
}

    int strangePrinter(string s) {
        
        s = removeduplicate(s);
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(0,n-1,s,dp);
    }
};