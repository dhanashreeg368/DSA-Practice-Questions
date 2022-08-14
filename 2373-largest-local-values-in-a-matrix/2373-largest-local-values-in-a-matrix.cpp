class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for(int i=0;i<n-2;++i) {
            for(int j=0;j<n-2;++j) {
                for(int ii=i;ii<i+3;++ii) {
                    for(int jj=j;jj<j+3;++jj) {
                        ans[i][j]=max(ans[i][j], grid[ii][jj]);
                    }
                }
            }
        }
        return ans;
    }
};