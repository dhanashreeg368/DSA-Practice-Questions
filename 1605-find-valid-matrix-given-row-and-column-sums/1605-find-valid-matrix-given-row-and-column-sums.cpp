class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        
        vector<vector<int>> matrix(rows, vector<int> (cols, 0));
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                int minValue = min(rowSum[i], colSum[j]);
                matrix[i][j] = minValue;
                rowSum[i]-=minValue;
                colSum[j]-=minValue;
            }
        }
        return matrix;
    }
};