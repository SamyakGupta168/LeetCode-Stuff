class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &v : edges) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], 2*v[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1) {
                dist[node] = min(dist[node], dis);
                continue;
            }

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if(dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return (dist[n-1] != INT_MAX) ? dist[n-1] : -1;
    }
};