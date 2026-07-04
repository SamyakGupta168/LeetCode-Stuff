class Solution {
public:
    using ll = long long;

    ll dfs(ll node, vector<ll>&dist, ll n, ll x, vector<vector<pair<int,int>>>&adj) {
        if(node == n-1) return 0;
        if(dist[node] != -1) return dist[node];
        dist[node] = LLONG_MAX;
        for(auto &it : adj[node]) {
            ll adjNode = it.first;
            ll edw = it.second;
            if(edw >= x) {
                ll pathDis = dfs(adjNode, dist, n, x, adj);
                if(pathDis == LLONG_MAX) continue;
                dist[node] = min(dist[node], edw + pathDis);
            }
        }
        return dist[node];
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto &x : edges) {
            int u = x[0], v = x[1], w = x[2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v, w});
        }
        
        auto check = [&](ll x) -> bool {
            vector<ll> dist(n, -1);
            dfs(0, dist, n, x, adj);
            return dist[0] <= (ll)k;
        };

        int low = 0, high = 1e9;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};