class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir=0; //to look for direction
        int top=0; //left corner
        int bottom=matrix.size()-1; //bottom corner
        int left=0; //bottom corner
        int right=matrix[0].size()-1; //right
        vector<int> ans;

        while(top<=bottom && left<=right)
        {
            if (dir==0) //going right
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==1) //going down
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir==2) //going left
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if (dir==3) //going up
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir=(dir+1)%4; //to change direction
        }
        return ans;
    }
};