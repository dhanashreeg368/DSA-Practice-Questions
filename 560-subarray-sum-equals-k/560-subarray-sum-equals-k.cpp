class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int> m;
        int n=nums.size();
        int ans=0;
        int sum=0;
        m[0]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if (m.count(sum - k)) ans += m[sum-k];
		    m[sum]++;
        }
        return ans;    
    }
};