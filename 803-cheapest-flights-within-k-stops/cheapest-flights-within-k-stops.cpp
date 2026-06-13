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
        // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {0, src}});
        dist[src] = 0;
        while(!q.empty()) {
            int stops = q.front().first;
            int dis=  q.front().second.first;
            int node = q.front().second.second;
            q.pop();

            if(stops == k+1) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                if(dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    q.push({stops + 1, {dist[adjNode], adjNode}});
                }
            }
        }

        return (dist[dst] != 1e9 ? dist[dst] : -1);
    }
};