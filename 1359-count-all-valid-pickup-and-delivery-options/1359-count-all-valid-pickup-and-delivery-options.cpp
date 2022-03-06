class Solution {
public:
    int countOrders(int n) {
        long long int ans=1;
        int m=1000000007;
		
        for(int i=2; i<=n; i++)ans=(ans*i)%m;
        for(int i=1; 2*n-i>1 ; i+=2)ans=(ans*(2*n-i)%m);
        
        return ans;
    }
};