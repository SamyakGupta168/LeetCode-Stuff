class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    const ll INF = 1e18;
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto &v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        vector<ll> dist(n, INF), ways(n, 0);
        dist[0] = 0, ways[0] = 1;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto &it : adj[node]) {
                ll adjNode = it.first;
                ll edgeWeight = it.second;
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    // if(adjNode == n-1) ways[adjNode] = ways[node];
                    // else ways[adjNode] = 1;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if(dis + edgeWeight == dist[adjNode]) {
                    ways[adjNode] = mod_add(ways[adjNode], ways[node], mod);
                }
            }
        }

        return ways[n-1];
    }
};