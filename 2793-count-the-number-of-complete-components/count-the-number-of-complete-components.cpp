class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, int &cnt, vector<int>&temp) {
        vis[node] = 1;
        temp.push_back(node);
        cnt++;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, cnt, temp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &x : edges) {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<vector<int>> list;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                vector<int> temp;
                int cnt = 0;
                dfs(i, adj, vis, cnt, temp);
                temp.push_back(cnt);
                list.push_back(temp);
            }
        }

        int ans = 0;
        for(auto &v : list) {
            int cnt = v.back();
            v.pop_back();
            bool flag = true;
            for(auto node : v) {
                if(adj[node].size() != cnt-1) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }

        return ans;
    }
};