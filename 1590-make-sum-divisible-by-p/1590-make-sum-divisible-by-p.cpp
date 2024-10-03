class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       map<int,int> mp;
       long long sum = 0;
       for (int i = 0; i<nums.size();++i) {
           sum+=nums[i];
       }
       int r = sum%p,res=INT_MAX; 
        sum = 0; 
        mp[0] = -1;
       if (r==0) {
           return 0;
       }
       for (int i=0; i<nums.size();++i) {
           sum+=nums[i];
           int x = sum%p, t = x-r; // case 1 when `x-y` is +ve 
           if(t>=0 && t<p && mp.find(t)!=mp.end()) {
               res = min(res,i-mp[t]);
           }
           t = x+p-r;  // case 2 when `x-y` is -ve 
           if (t>=0 && t<p && mp.find(t)!=mp.end()) {
               res = min(res,i-mp[t]);
           }
           mp[x] = i;  // store the latest index for remainder x as we want subarray to be smallest.
       }
       if (res==nums.size()) {
           res=-1;
       }
       return res;
    }
};