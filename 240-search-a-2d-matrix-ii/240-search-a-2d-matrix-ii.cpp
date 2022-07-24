class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n = m ? matrix[0].size() : 0;
        int r=0, c=n-1; //for curr row and col 
        while(r<m && c>=0) 
        {
            if (matrix[r][c]==target) //if we get target 
            {
                return true;
            }
            if (matrix[r][c]>target) //if curr val is greater move to previous col else move to next row
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};