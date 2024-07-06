class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& modImage, int iniColor, int color, int delrow[], int delcol[]) {
        modImage[row][col]= color; // set new color for starting cell
        int n = modImage.size();
        int m = modImage[0].size();
        // find its neighbours
        for (int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            // call dfs only if valid nodes
            // valid when - rows and cols are valid, cell is equal to initial color and cell is not                     // previously colored with new color
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                modImage[nrow][ncol]==iniColor && modImage[nrow][ncol]!=color)
                dfs(nrow, ncol, image, modImage, iniColor, color, delrow, delcol);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>& modImage = image; // modified image
        int iniColor = modImage[sr][sc]; // inital color
        
        // for finding neighbours 
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, modImage, iniColor, color, delrow, delcol); // call dfs
        return modImage;
    }
};