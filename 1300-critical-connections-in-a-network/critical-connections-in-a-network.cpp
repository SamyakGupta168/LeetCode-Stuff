class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&time, vector<int>&low, int &t, vector<vector<int>>&ans) {
        t++;
        time[node] = t;
        low[node] = t;
        for(auto it : adj[node]) {
            if(!time[it]) {
                dfs(it, node, adj, time, low, t, ans);
                low[node] = min(low[node], low[it]);
                if(time[node] < low[it]) {
                    ans.push_back({node, it});
                }
            } else if(it != parent) {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<vector<int>> ans;
        vector<int> time(n, 0), low(n, INT_MAX);
        int t = 0;
        for(int i=0;i<n;i++) {
            if(!time[i]) dfs(i, -1, adj, time, low, t, ans);
        }

        return ans;
    }
};