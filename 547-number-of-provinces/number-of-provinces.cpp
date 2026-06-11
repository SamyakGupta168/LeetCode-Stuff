class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj, int n) {
        vis[node] = 1;
        for(int i=0;i<n;i++) {
            if(adj[node][i] && !vis[i]) {
                dfs(i, vis, adj, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size(); // n --> No of cities
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, vis, adj, n);
            }
        }

        return cnt;
    }
};