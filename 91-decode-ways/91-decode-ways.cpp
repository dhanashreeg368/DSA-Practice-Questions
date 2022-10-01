class Solution {
public:
    int solve(string s, vector <int> &dp)
    {
        int n = s.length();
		
		// If length is zero then we got one way to decode the string so return 1
        if(n == 0)
            return 1;
			
		// If the starting chracter of the string is zero then the possible ways to decode are zero so return 0
        else if(s[0] == '0')
            return 0;
			
		// if we already solve this string then return the stored value (memoized value)
        else if(dp[n] != -1)
            return dp[n];
        
        int a = 0, b = 0;
		//Take only the starting character of string and call recursive for the rest of string
        a = solve(s.substr(1), dp);
		
		//Take two character of string if it is possible (length of string should be atleast 2 and the string must be between 0 to 26) and call recursive for the rest of the string
        if( (n > 1) && ( (s[0] == '1') || (s[0] == '2' && s[1] <= '6')))
            b = solve(s.substr(2), dp);
        
		//Store the solve value of the string for further use
        dp[n] = a+b;
        return dp[n];
    }
	int numDecodings(string s) 
    {
        int n = s.length();
        vector <int> dp(n+1, -1);
        return solve(s, dp);
    }
};