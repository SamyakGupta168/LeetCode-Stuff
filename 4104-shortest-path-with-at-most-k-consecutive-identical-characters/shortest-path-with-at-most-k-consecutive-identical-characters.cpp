class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // {dist, {node, streak}}
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        dist[0][1] = 0;
        pq.push({0, {0, 1}});
        int ans = INT_MAX;

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int streak = pq.top().second.second;
            pq.pop();

            if(dis != dist[node][streak]) continue;

            if(node == n-1) {
                if(streak <= k) ans = min(ans, dis);
                continue;
            }
            if(streak > k) continue;

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;
                int newStreak = 0;
                if(labels[node] == labels[adjNode]) {
                    newStreak = streak + 1;
                } else {
                    newStreak = 1;
                }

                if(newStreak > k) continue;

                if(dis + edw < dist[adjNode][newStreak]) {
                    dist[adjNode][newStreak] = dis + edw;
                    pq.push({dist[adjNode][newStreak], {adjNode, newStreak}});
                }
            }
        }

        return (ans != INT_MAX ? ans : -1);
    }
};