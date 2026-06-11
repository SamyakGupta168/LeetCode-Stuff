class Solution {
public:
    void dijkstra(int src, vector<vector<pair<int,int>>>&adj, vector<int>&timeTaken, int n) {
        timeTaken[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < timeTaken[adjNode]) {
                    timeTaken[adjNode] = dis + wt;
                    pq.push({timeTaken[adjNode], adjNode});
                }
            }
        }

        for(auto &it : timeTaken) {
            if(it == INT_MAX) it = -1;
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        vector<int> timeTaken(n+1, INT_MAX);
        dijkstra(src, adj, timeTaken, n);

        int minTime = 0;
        for(int i=1;i<=n;i++) {
            if(timeTaken[i] == -1) return -1; 
            minTime = max(minTime, timeTaken[i]);
        }

        return minTime;
    }
};