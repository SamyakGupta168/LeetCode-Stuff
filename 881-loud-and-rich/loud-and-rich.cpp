class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&temp, vector<int>&quiet) {
        vis[node] = node, temp[node] = quiet[node];
        for(auto it : adj[node]) {
            if(vis[it] == -1) dfs(it, adj, vis, temp, quiet);
            if(temp[it] < temp[node]) {
                temp[node] = temp[it];
                vis[node] = vis[it];
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto &x : richer) {
            int u = x[1], v = x[0];
            adj[u].push_back(v);
        }

        vector<int> vis(n, -1), temp(n, -1);
        for(int i=0;i<n;i++) {
            if(vis[i] == -1) dfs(i, adj, vis, temp, quiet);
        }

        return vis;
    }
};