class Solution {
    void dijkstra(int node, vector<pair<int,int>> adj[], vector<int>& dist) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[node] = 0;
        pq.push({0, node});
        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adj_node = it.first;
                int wt = it.second;
                if (cost + wt < dist[adj_node]) {
                    dist[adj_node] = cost + wt;
                    pq.push({dist[adj_node], adj_node});
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
                        
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = original.size();
        vector<pair<int,int>> adj[26];
        for (int i = 0; i < n; i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        vector<vector<int>> cost_matrix(26, vector<int>(26, 1e9));
        for (int i = 0; i < 26; i++) {
            dijkstra(i, adj, cost_matrix[i]);
        }
        long long final_cost = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) {
                continue;
            }
            if (cost_matrix[source[i] - 'a'][target[i] - 'a'] == 1e9) {
                return {-1};
            } else {
                final_cost += cost_matrix[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return final_cost;
    }
};