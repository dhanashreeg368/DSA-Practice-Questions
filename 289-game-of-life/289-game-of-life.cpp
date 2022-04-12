class Solution {
public:
     bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector <int> dx = {1,1,0,-1,-1,-1,0,1}; //vector for neighbours
        vector <int> dy = {0,1,1,1,0,-1,-1,-1};
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                int cnt_live_neighbors=0;
                for(int i=0;i<8;i++)
                {
                    int cur_x=row+dx[i], cur_y=col+dy[i];
                    if (isValidNeighbor(cur_x, cur_y, board) && abs(board[cur_x][cur_y]) == 1)
                        cnt_live_neighbors++;
                }
                
                if (board[row][col] == 1 && (cnt_live_neighbors < 2 || cnt_live_neighbors > 3))
                    board[row][col] = -1;
                
                if (board[row][col] == 0 && cnt_live_neighbors == 3)
                    board[row][col] = 2;
            }
        }
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] >= 1)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }
};