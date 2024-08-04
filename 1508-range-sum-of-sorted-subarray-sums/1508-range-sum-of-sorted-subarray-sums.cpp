class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        vector<int> res;
        vector<int> prefixSums(n+1, 0);
        
        // compute prefix sums
        for(int i=0; i<n; i++) {
            prefixSums[i+1] = (prefixSums[i] + nums[i]) % mod;
        }
        
        // generate all subarray sums
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i+1; j<=n; j++) {
                res.push_back((prefixSums[j] - prefixSums[i] + mod) % mod);
            }
        }
        
        // sort
        sort(res.begin(), res.end());
        
        // calculate range sum
        int sum = 0;
        for(int i = left-1; i<right; i++) {
            sum = (sum + res[i]) % mod;
        }
        
        return sum;
    }
};