class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto x : edges) {
            int u = x[0], v = x[1];
            degree[u]++, degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<int> vis(n);
        for(int i=0;i<n;i++) {
            if(degree[i] == 1) {
                q.push(i);
                vis[i] = 1;
            }
        }

        int rem = n;
        while(rem > 2) {
            int sz = q.size();
            rem -= sz;
            for(int i=0;i<sz;i++) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        degree[it]--;
                        if(degree[it] == 1) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        vector<int> nodes;
        while(!q.empty()) {
            nodes.push_back(q.front());
            q.pop();
        }

        return nodes;
    }
};