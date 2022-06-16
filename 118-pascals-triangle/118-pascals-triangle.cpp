class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows); //creating new 2d vector 
        
        for(int i=0;i<numRows;i++) //for rows 
        {
            pascal[i].resize(i+1); //change size to i+1
            pascal[i][0]=pascal[i][i]=1; //set last and first val to 1
            
            for(int j=1;j<i;j++) //for cal sum of other elements 
            {
                pascal[i][j]=pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};