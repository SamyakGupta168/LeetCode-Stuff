class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        ll V = n;
        vector<vector<pair<ll,ll>>> adj(V);
        for(auto &v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        vector<ll> ways(V, 0), dist(V, LLONG_MAX);
        ways[0] = 1;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            for(auto &it : adj[node]) {
                ll adjNode = it.first;
                ll edw = it.second;
                if(dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if(dis + edw == dist[adjNode]) {
                    ways[adjNode] += ways[node];
                    ways[adjNode] %= mod;
                }
            }
        }
        
        return ways[V-1] % mod;
    }
};