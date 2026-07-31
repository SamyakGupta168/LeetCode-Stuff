class Solution {
public:
    int topo(vector<vector<int>>&adj, vector<int>&pos, int n) {
        vector<int> indegree(n+1);
        for(auto &v : adj) {
            for(auto x : v) indegree[x]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(!indegree[i]) q.push(i);
        }

        int idx = 0;
        while(!q.empty()) {
            int node = q.front();
            pos[node] = idx;
            idx++;
            q.pop();
            for(auto it : adj[node]) {
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }

        return idx;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adj1(k+1), adj2(k+1);
        for(auto &x : rowConditions) {
            int u = x[0], v = x[1];
            adj1[u].push_back(v);
        }

        for(auto &x : colConditions) {
            int u = x[0], v = x[1];
            adj2[u].push_back(v);
        }

        vector<int> row(k+1, -1), col(k+1, -1);
        int cnt1 = topo(adj1, row, k);
        int cnt2 = topo(adj2, col, k);

        if(cnt1 != k || cnt2 != k) return vector<vector<int>> ();

        vector<vector<int>> ans(k, vector<int>(k));
        for(int i=1;i<=k;i++) ans[row[i]][col[i]] = i;

        return ans;
    }
};