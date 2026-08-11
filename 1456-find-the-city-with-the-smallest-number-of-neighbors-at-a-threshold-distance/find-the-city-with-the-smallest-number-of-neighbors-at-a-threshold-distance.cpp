class Solution {
public:
    void dijkstra(int src, vector<vector<pair<int,int>>>&adj, vector<int>&dist) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if(dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &x : edges) {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int minCnt = INT_MAX, city = -1;
        for(int i=0;i<n;i++) {
            vector<int> dist(n, INT_MAX);
            dijkstra(i, adj, dist);
            int cnt = 0;
            for(auto x : dist) {
                cnt += (x <= th);
            }
            if(cnt < minCnt) {
                minCnt = cnt;
                city = i;
            } else if(cnt == minCnt) city = i;
        }

        return city;
    }
};