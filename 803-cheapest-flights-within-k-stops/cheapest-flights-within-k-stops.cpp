class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &v : flights) {
            int from = v[0];
            int to = v[1];
            int wt = v[2];
            adj[from].push_back({to, wt});
        }

        vector<int> dist(n, 1e9);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, src}});
        dist[src] = 0;
        while(!pq.empty()) {
            int stops = pq.top().first;
            int dis=  pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(stops == k+1) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if(dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    pq.push({stops + 1, {dist[adjNode], adjNode}});
                }
            }
        }

        return (dist[dst] != 1e9 ? dist[dst] : -1);
    }
};