class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;

    void dijkstra(ll src, vector<vector<pair<ll,ll>>>&adj, vector<ll>&dist, ll n) {
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            ll node = pq.top().second;
            ll dis = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]) {
                ll adjNode = it.first;
                ll edw = it.second;
                if(dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto &x : edges) {
            ll u = x[0], v = x[1], w = x[2];
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<ll> dist(n, INT_MAX);
        dijkstra(n-1, adj, dist, n);

        vector<ll> nodes(n, 0);
        iota(nodes.begin(), nodes.end(), 0LL);
        sort(nodes.begin(), nodes.end(), [&] (auto u, auto v) ->bool {
            return dist[u] < dist[v];
        });

        vector<ll> ways(n, 0); 
        ways[n-1] = 1;
        for(auto node : nodes) {
            for(auto it : adj[node]) {
                ll adjNode = it.first;
                if(dist[node] < dist[adjNode]) {
                    ways[adjNode] += ways[node];
                    ways[adjNode] %= mod;
                }
            }
        }

        return (int)ways[0];
    }
};