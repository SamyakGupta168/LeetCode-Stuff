class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        for(auto &x : rel) {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(n+1);
        for(auto &v : adj) {
            for(auto x : v) indegree[x]++;
        }

        vector<int> compTime(n+1, 0);
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++) {
            if(!indegree[i]) {
                compTime[i] = time[i-1];
                q.push({compTime[i], i});
            }
        }
        
        int maxTime = 0;

        while(!q.empty()) {
            int ct = q.front().first;
            int node = q.front().second;
            q.pop();

            maxTime = max(maxTime, ct);

            for(auto it : adj[node]) {
                compTime[it] = max(compTime[it], time[it-1] + ct);
                indegree[it]--;
                if(!indegree[it]) q.push({compTime[it], it});
            }
        }

        return maxTime;
    }
};