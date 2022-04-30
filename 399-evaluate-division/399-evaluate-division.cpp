class Solution {
public:
    //Doing just simple DFS from source to destination and calculating the cost to reach there, 
//it will be the multiplication of edges weight between them
    void dfs(string src, string dst, unordered_map<string, vector<pair<string,double>>> &graph, unordered_map<string, int> &vis, double temp, double &ans)
    {
        vis[src]++;
        if(src == dst)
        {
            ans = temp;
            return;
        }
        
        for(auto nd:graph[src])
        {   
            auto v = nd.first;
            auto cost = nd.second;
            if(!vis[v])
            {
                dfs(v, dst, graph, vis, temp*cost, ans);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> graph;
        
        //Create graph considering each equation as an edge with weight as value between them
        //Make a directed graph as a ---- > b && b ---- > a with weight value[i] and 1/value[i] resp
        for(int i=0; i<eq.size(); i++)      
        {                                               
            graph[eq[i][0]].push_back({eq[i][1], values[i]});
            graph[eq[i][1]].push_back({eq[i][0], 1/values[i]});
        }
        
        vector<double> res;
        for(auto q:queries)                 //To find ans, find the path from query[0] to query[1] in graph,
        {                                   //ans will be the multiplication of edges weight to reach there
            unordered_map<string, int> vis;
            double temp = 1;
            double ans = -1;
            if(graph.find(q[0]) != graph.end()) //If you dont find the starting node in graph then ans = -1
            {
                dfs(q[0], q[1], graph, vis, temp, ans);           
            }
            res.push_back(ans);
        }
        
        return res;
        
    }
};