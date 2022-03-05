class Solution {
public:
    unordered_map<int, int> pts;
    unordered_map<int, int> dp;
    int deleteAndEarn(vector<int>& nums) {
        int mx=nums[0];
        for(int i=0; i<nums.size(); i++) {
            pts[nums[i]]+=nums[i];
            mx=max(nums[i],mx);
        }
         return mnop(mx);
    }
    int mnop(int num) {
        if(num==0)
            return 0;
        if(num==1) 
            return (pts.count(1) ? pts[1]:0);
        if(dp.count(num))
            return dp[num];
        int x=(pts.count(num) ? pts[num]:0);
        dp[num]=max(mnop(num-1), mnop(num-2)+x);
        return dp[num];
    }
};