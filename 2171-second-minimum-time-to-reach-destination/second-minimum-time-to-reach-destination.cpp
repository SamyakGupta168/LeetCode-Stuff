class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        dp[0][0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            int curTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto adjNode : adj[node]) {
                int wt = 0;
                if((curTime/change) % 2 == 0) {
                    wt = time;
                } else {
                    wt = (change - (curTime % change)) + time;
                }  
                if(curTime + wt < dp[adjNode][0]) {
                    dp[adjNode][1] = dp[adjNode][0];
                    dp[adjNode][0] = curTime + wt;
                    pq.push({dp[adjNode][0], adjNode});
                } else if(curTime + wt < dp[adjNode][1] && dp[adjNode][0] < curTime + wt) {
                    dp[adjNode][1] = curTime + wt;
                    pq.push({dp[adjNode][1], adjNode});
                }
            }
        }

        return dp[n-1][1];
    }
};