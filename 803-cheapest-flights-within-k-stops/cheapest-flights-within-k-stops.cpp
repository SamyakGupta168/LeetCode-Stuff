class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<pair<int,int>, int>> q;
        dist[src] = 0;
        q.push({{0, src}, 0});

        while(!q.empty()) {
            int stops = q.front().first.first;
            int node = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(stops == k+1) continue;

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    q.push({{stops+1, adjNode}, dist[adjNode]});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};