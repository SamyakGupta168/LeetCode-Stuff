class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> dist(n, INT_MAX);
        // priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, greater<pair<pair<int,int>, int>>> pq;
        // Priority queue will store this {{stops, dist}, node}
        queue<pair<pair<int,int>, int>> pq;
        dist[src] = 0;
        pq.push({{0, 0}, src});
        int ans = INT_MAX;
        while(!pq.empty()) {
            int stops = pq.front().first.first;
            int dis = pq.front().first.second;
            int node = pq.front().second;
            pq.pop();

            if(stops > k) continue;
            // if(node == dst) ans = min(ans, dis);

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    if(adjNode == dst) pq.push({{stops, dist[adjNode]}, adjNode});
                    else pq.push({{stops+1, dist[adjNode]}, adjNode});
                }
            }
        }

        return ((dist[dst] == INT_MAX) ? -1 : dist[dst]);
    }
};