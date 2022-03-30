class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //using directions
        auto rows=matrix.size();
        if (rows==0) return false;
        auto cols=matrix[0].size();
        if (cols==0) return false;
        int i=rows-1;
        int j=0;
        while(i>=0 && j<cols)
        {
            if (matrix[i][j] == target) return true;
            if (target > matrix[i][j]) {
                j ++;
            } else {
                i --;
            }
        }
            return false;
        }
};