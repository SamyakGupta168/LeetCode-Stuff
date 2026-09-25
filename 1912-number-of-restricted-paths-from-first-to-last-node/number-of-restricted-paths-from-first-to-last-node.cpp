class Solution {
public:
    int mod = 1e9 + 7;

    int dfs(int node, vector<vector<pair<int,int>>>&adj, vector<int>&dp, vector<int>&dist) {
        if(node == 0) return 1;
        if(dp[node] != -1) return dp[node];
        int cnt = 0;
        dp[node] = 0;
        for(auto &x : adj[node]) {
            int adjNode = x.first;
            if(dist[node] < dist[adjNode]) {
                cnt += dfs(adjNode, adj, dp, dist);
                cnt %= mod;
            }
        }
        return dp[node] = cnt;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) {
            int u = e[0]-1, v = e[1]-1, wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> dist(n, INT_MAX);
        dist[n-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, n-1});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis != dist[node]) continue;

            for(auto &x : adj[node]) {
                int adjNode = x.first, wt = x.second;
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        vector<int> dp(n, -1);
        return dfs(n-1, adj, dp, dist);        
    }
};