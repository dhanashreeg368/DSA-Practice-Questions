class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
         vector<vector<int>> ans(2); //for storing ans
         map<int, int> mp; //for storing frequency
         for (auto i:matches) //traverse in given matches 
         {
             if (!mp.count(i[0])) //if count is not found before add zero as cnt
                 mp[i[0]]=0;
                 mp[i[1]]++;
         }
         for(auto &[m,n]:mp)
         {
             if(n==0) ans[0].push_back(m);
             else if(n==1) ans[1].push_back(m);
         }
        return ans;
    }
};