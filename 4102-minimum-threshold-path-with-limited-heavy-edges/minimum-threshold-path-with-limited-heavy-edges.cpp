class Solution {
public:
    bool dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src, int tar, int th, int k) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto &it : adj[node]) {
            int edw = (it.second > th);
            int adjNode = it.first;
            if(dis + edw < dist[adjNode]) {
                dist[adjNode] = dis + edw;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

        return (dist[tar] <= k);
    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int tar, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &v : edges) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        int low = 0, high = 1e9 + 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(dijkstra(n, adj, src, tar, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};