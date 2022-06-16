class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> dummy1(rows,-1); //dummy for rows 
        vector<int> dummy2(cols,-1); //dummy for cols
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if (matrix[i][j]==0)
                {
                    dummy1[i]=0; //if zero update in rows and cols
                    dummy2[j]=0;
                }
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++) //traverse again 
            {
                if (dummy1[i]==0 || dummy2[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};