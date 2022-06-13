class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> newt(triangle.back());
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                newt[j]=min(newt[j],newt[j+1])+triangle[i][j];
            }
        }
        return newt[0];
    }
};