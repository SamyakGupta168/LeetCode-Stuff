class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& pf) {
        int n = pf.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto &x : edges) {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> dist(n, vector<int>(maxTime+1, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        dist[0][0] = pf[0];
        pq.push({pf[0], {0, 0}});
        while(!pq.empty()) {
            int cost = pq.top().first;
            int time = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            // if(cost != dist[node][time]) continue;
            if(node == n-1 || time >= maxTime) continue;

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                int newTime = time + edw;
                if(newTime <= maxTime && cost + pf[adjNode] < dist[adjNode][newTime]) {
                    dist[adjNode][newTime] = cost + pf[adjNode];
                    pq.push({dist[adjNode][newTime], {newTime, adjNode}});
                }
            }
        }

        int ans = INT_MAX;
        for(auto cost : dist[n-1]) ans = min(ans, cost);

        return (ans != INT_MAX ? ans : -1);
    }
};