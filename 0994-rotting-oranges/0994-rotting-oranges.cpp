class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int cntFresh = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        // queue {{row, col}, time}}
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i< n; i++) {
            for (int j = 0; j< m; j++) {
                if (grid[i][j] == 2 ) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int tim = 0;
        int cnt=0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tim = max(tim, t);
            // find its neighbours
            for (int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    vis[nrow][ncol]==0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (vis[i][j]!=2 && grid[i][j] == 1) {
                    return -1;
                } 
            }
        }
      return tim;  
    }
};