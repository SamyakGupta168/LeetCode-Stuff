class Solution {
public:
    int dfs(int node, vector<vector<int>>&adj, vector<int>&ans, vector<int>&quiet) {
        ans[node] = node;
        for(auto adjNode : adj[node]) {
            if(ans[adjNode] == -1) {
                int nn = dfs(adjNode, adj, ans, quiet);
                if(quiet[nn] < quiet[ans[node]]) {
                    ans[node] = nn;
                }
            } else if(quiet[ans[adjNode]] < quiet[ans[node]]) {
                ans[node] = ans[adjNode];
            }
        }
        return ans[node];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto &e : richer) {
            int u = e[1], v = e[0];
            adj[u].push_back(v);
        }

        vector<int> ans(n, -1);
        for(int i=0;i<n;i++) {
            if(ans[i] == -1) {
                dfs(i, adj, ans, quiet);
            }
        }

        return ans;
    }
};