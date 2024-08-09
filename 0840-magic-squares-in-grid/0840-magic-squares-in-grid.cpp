class Solution {
public:
        bool isMagicSquare(vector<vector<int>>& grid , int r , int c){

        // condition
        // Every elemnet from 1 to 9 and each distinct 
        // row , col , diag, anti diag sum equal

        unordered_set <int> s;
        for(int i=r ; i<r+3 ; i++){
            for(int j= c ; j<c+3 ; j++){
                int num = grid[i][j];
                if(s.count(num) || num < 1 || num > 9 ){
                    return false;
                }else{
                    s.insert(num);
                }
            }
        }

        int row_sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        for(int i=0 ; i<3 ; i++){

            int rSum = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
            if(rSum != row_sum) return false;

            int cSum = grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i];
            if(cSum != row_sum) return false;

        }

        // Diagonal 
        int dSum = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];

        if(dSum != row_sum) return false;

        // Anti Diagonal 
        int aSum = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] ;
        
        if(aSum != row_sum) return false;

        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        for(int i=0 ; i<= rows-3 ; i++){
            for(int j=0 ; j<= cols-3 ; j++){
                if(isMagicSquare(grid,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};