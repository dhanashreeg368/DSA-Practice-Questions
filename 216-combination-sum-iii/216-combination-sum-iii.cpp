class Solution {
public:
    void solve(int st,int k,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(k<=0)
        {
            if(n==0) ans.push_back(ds);
            return;
        }
        
        for(int i=st;i<=9;i++)    
        {
            ds.push_back(i);
            solve(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};