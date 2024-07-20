class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
             int delrow[], int delcol[], int n, int m) {
        vis[row][col] = 1; // Mark the current cell as visited
        for (int i = 0; i < 4; i++) { // Iterate over all 4 possible directions
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, delrow, delcol, n, m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        // Traverse boundary elements
        for (int i = 0; i < n; i++) { // loop through rows
            for (int j = 0; j < m; j++) { // loop through cols
                if (i == 0 || j == 0 || i == n-1 || j == m-1) { // Check if the cell is on the boundary
                    if (grid[i][j] == 1 && !vis[i][j]) {
                        dfs(i, j, vis, grid, delrow, delcol, n, m);
                    }
                }
            }
        }
        
        int cnt = 0; // for finding enclave lands 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};