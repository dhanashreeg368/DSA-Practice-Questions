class Solution {
public:
    //function for comparison
    static bool compare(pair<int,int> k1, pair<int,int> k2)
    {
        if(k1.second!=k2.second) //if different vals return min
        {
            return k1.second<k2.second;
        }
        else //if same value return idx with min value
        {
            return k1.first<k2.first; 
        }
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vec; //vec pair to store index and number of soldiers at particular idx
        //counting soldiers in each row
        vector<int> ans; //to store ans
        for(int i=0;i<mat.size();i++)
        {
            int soldiers=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    soldiers++;
                }
            }
            vec.push_back(make_pair(i,soldiers)); //making pairs
        }
        sort(vec.begin(),vec.end(),compare); //sort vec: use comparator for a condition
        for(int i=0;i<k;i++) //store idx in ans 
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};