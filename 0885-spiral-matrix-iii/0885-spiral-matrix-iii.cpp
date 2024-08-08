class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int r = rStart;
        int c = cStart;
        int d = 0; // right (d == 0 right, 1 down, 2 left, 3 up)
            
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};
        
        // Start by pushing the initial position
        result.push_back({r, c});
        
        // We start with one step for each direction
        int steps = 1;

        while (result.size() < rows * cols) {
            for (int i = 0; i < 2; ++i) { // There are two turns before increasing the steps
                for (int j = 0; j < steps; ++j) {
                    // Calculate next position
                    r += delrow[d];
                    c += delcol[d];
                    
                    // Check if the position is within the bounds of the grid
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                // Change direction
                d = (d + 1) % 4;
            }
            // Increase steps after two directions
            steps++;
        }

        return result;
    }
};