class Solution {
public:
    int minCost(int mxt, vector<vector<int>>& edges, vector<int>& pf) {
        int n = pf.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

       vector<vector<int>> dp(n, vector<int>(mxt+1, INT_MAX));
       dp[0][0] = pf[0];
       priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {dp[0][0], 0}});
        while(!pq.empty()) {
            int time = pq.top().first;
            int cost = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if(dp[node][time] != cost) continue;

            for(auto &x : adj[node]) {
                int adjNode = x.first, wt = x.second;
                if(time + wt > mxt) continue;
                if(cost + pf[adjNode] < dp[adjNode][time + wt]) {
                    dp[adjNode][time + wt] = cost + pf[adjNode];
                    pq.push({time + wt, {dp[adjNode][time + wt], adjNode}});
                }
            }
        }

        int ans = *min_element(dp[n-1].begin(), dp[n-1].end());

        return (ans != INT_MAX ? ans : -1);
    }
};