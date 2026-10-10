class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(n, vector<int>((1<<n), -1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            int mask = (1 << i);
            q.push({i, mask});
            dp[i][mask] = 0;
        }

        while(!q.empty()) {
            int node = q.front().first;
            int mask = q.front().second;
            q.pop();
            if(mask == (1 << n) - 1) return dp[node][mask];
            for(auto v : graph[node]) {
                if(dp[v][mask|(1<<v)] == -1) {
                    dp[v][mask|(1<<v)] = dp[node][mask] + 1;
                    q.push({v, mask|(1<<v)});
                }
            }
        }

        return -1;
    }
};