class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[0][0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            if(node == n-1 && dist[node][1] == dis) return dis;

            for(auto adjNode : adj[node]) {
                int dd = dis + time;
                int r = dis / change;
                if(r & 1) dd += change - (dis % change);
                if(dd < dist[adjNode][0]) {
                    dist[adjNode][1] = dist[adjNode][0];
                    dist[adjNode][0] = dd;
                    pq.push({dd, adjNode});
                } else if(dd < dist[adjNode][1] && dd > dist[adjNode][0]) {
                    dist[adjNode][1] = dd;
                    pq.push({dd, adjNode});
                }
            }
        }

        return -1;
    }
};