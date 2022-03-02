class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    multimap<int,int> distance;
    for(int i=0;i<points.size();i++)
    {
        int d=euclid(points[i][0],points[i][1]); 
        distance.insert(pair<int,int>(d,i));
    }
    vector<vector<int>> ans;
    for(auto it=distance.begin();it!=distance.end();it++)
    {
        if (k>0)
        {
            ans.push_back(points[it->second]);
        }
        --k;
    }
    return ans;
    }
    int euclid(int a,int b)
    {
        int sqa=a*a;
        int sqb=b*b;
        return (sqa+sqb);
    }
};