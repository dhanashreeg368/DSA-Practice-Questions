class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> mem(n+1,vector<int>(target+1,0));
		/*
			Initializing base cases.
		*/
		mem[0][0] = 1;
        mem[1][1] = 1;
        /*
			- Calculate ways to get "sum" for "i" number of dice with k faces.
			- For "i" number of dice, to get "sum". ways =  number of ways with "i-1" dice.
			- Number of ways with "i-1" dice  = "j" (1....k)  possible ways, 
			- i.e. no. of ways to get (sum-1) + (sum-2) + ....(sum-k) with "i-1" dice.
		
		*/
        for(int i=1;i<=n;i++){
            for(int sum=0; sum <= target; sum++){
                int ways = 0;
                for(int j=1; j<=k && j<=sum ; j++){
                    ways = (ways + mem[i-1][sum-j]) % 1000000007;
                }
                mem[i][sum] = ways;
            }
        }
        
        return mem[n][target];
    }
};