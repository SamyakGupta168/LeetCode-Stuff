class Solution {
public:
    bool dfs(int node, int V, vector<vector<int>>&adj, vector<int>&vis, vector<int>&pathVis) {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, V, adj, vis, pathVis)) return true;
            } else if(pathVis[it]) {
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }

    bool canFinish(int courses, vector<vector<int>>& preReq) {
        int V = courses;
        vector<vector<int>> adj(V);
        for(auto &v : preReq) {
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(V, 0), pathVis(V, 0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i, V, adj, vis, pathVis)) return false;
            }
        }
        return true;
    }
};