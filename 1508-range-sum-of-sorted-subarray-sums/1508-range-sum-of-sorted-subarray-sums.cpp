class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        vector<int> res;
        
        // generate all subarray sums
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum = (sum + nums[j]) % mod;
                res.push_back(sum);
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