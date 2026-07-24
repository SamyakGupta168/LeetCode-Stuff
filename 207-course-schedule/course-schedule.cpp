class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>&adj) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(!dfs(it, vis, pathVis, adj)) return false;
            } else if(pathVis[it]) return false;
        }
        pathVis[node] = 0;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
        for(auto &v : pr) {
            adj[v[1]].push_back(v[0]);
        }

        vector<int> vis(n, 0), pathVis(n, 0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(!dfs(i, vis, pathVis, adj)) return false;
            }
        }

        return true;
    }
};