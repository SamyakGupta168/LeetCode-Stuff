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
        // dist[node][stop] -> minimum cost to reach 'node' with exactly 'stop' stops.
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, src}});
        dist[src][0] = 0;
        while(!pq.empty()) {
            int dis = pq.top().first;
            int stops = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(node == dst || stops == k+1) continue;

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if(dis + edw < dist[adjNode][stops+1]) {
                    dist[adjNode][stops+1] = dis + edw;
                    pq.push({dist[adjNode][stops+1], {stops+1, adjNode}});
                }
            }
        }

        int ans = INT_MAX;
        for(auto dis : dist[dst]) ans = min(ans, dis);

        return (ans != INT_MAX ? ans : -1); 
    }
};