class Solution {
public:
    using ll = long long;

    vector<ll> dijkstra(int V, vector<vector<pair<int,ll>>> &adj, int src) {

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    vector<ll> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        ll dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto &it : adj[node]) {
            ll edgeWeight = it.second;
            int adjNode = it.first;
            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}


    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int,ll>>> adj1(n), adj2(n);
        for(auto &r : roads) {
            adj1[r[0]].push_back({r[1], r[2]});
            adj1[r[1]].push_back({r[0], r[2]});
            adj2[r[0]].push_back({r[1], (ll)r[2]*r[3]});
            adj2[r[1]].push_back({r[0], (ll)r[2]*r[3]});
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            vector<ll> dist1 = dijkstra(n, adj1, i);
            vector<ll> dist2 = dijkstra(n, adj2, i);
            ll mn = LLONG_MAX;
            for(int j=0;j<n;j++) {
                mn = min(mn, dist1[j] + dist2[j] + prices[j]);
            }
            ans[i] = mn;
        }

        return ans;
    }
};