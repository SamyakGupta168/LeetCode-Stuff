class Solution {
public:
    void dfs(int node, vector<int>&time, vector<int>&low, vector<vector<int>>&adj, int t, vector<vector<int>>&edges, int parent) {
        t++;
        time[node] = t;
        low[node] = time[node];

        for(auto it : adj[node]) {
            if(!time[it]) {
                dfs(it, time, low, adj, t, edges, node);
                low[node] = min(low[node], low[it]);
                if(time[node] < low[it]) {
                    edges.push_back({node, it});
                }
            } else if(it != parent) {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>> adj(n);
        for(auto &e : conn) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n, 0), low(n, INT_MAX);
        vector<vector<int>> edges;
        dfs(0, time, low, adj, 0, edges, -1);
        return edges;
    }
};