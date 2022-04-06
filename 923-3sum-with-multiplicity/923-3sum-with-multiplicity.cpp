class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        int mod=1e9+7;
        int ans=0;
        unordered_map<int,int> mp; //to store sum of pairs 
        for(int i=0;i<n;i++)
        {
            ans = (ans + mp[target - arr[i]]) % mod;
            for(int j=0; j<i; j++) 
            {
                mp[arr[i] + arr[j]]++;
            }
        }
        return ans;        
    }
};