class Solution {
public:
    int mod = 1e9 + 7;

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(auto &v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int e = -1;
        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()) {
            e++;
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }

        int ans = 1;
        for(int i=1;i<e;i++) {
            ans *= 2;
            ans %= mod;
        }

        return ans;
    }
};