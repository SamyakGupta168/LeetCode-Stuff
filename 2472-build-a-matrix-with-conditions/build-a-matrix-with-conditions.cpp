class Solution {
public:
    bool topo(int n, vector<vector<int>> order, vector<int>&res) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto &e : order) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++) {
            if(!indegree[i]) q.push(i);
        }
        
        int idx = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res[node] = idx++;
            for(auto adjNode : adj[node]) {
                indegree[adjNode]--;
                if(!indegree[adjNode]) {
                    q.push(adjNode);
                }
            }
        }

        return (idx == n);
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<int> row(k), col(k);
        bool flag1 = topo(k, rc, row);
        bool flag2 = topo(k, cc, col);

        if(!flag1 || !flag2) return vector<vector<int>>();

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0;i<k;i++) ans[row[i]][col[i]] = i+1;
        return ans;
    }
};