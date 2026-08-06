class Solution {
public:
    void dfs1(int node, vector<int>&mark, vector<vector<int>>&adj) {
        mark[node] = 1;
        for(auto it : adj[node]) {
            if(!mark[it]) dfs1(it, mark, adj);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        vector<vector<int>> adj(n);
        for(auto &x : in) {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
        }

        vector<int> mark(n, 0);
        dfs1(k, mark, adj);

        bool flag = false;
        for(int i=0;i<n;i++) {
            if(!mark[i]) {
                for(auto it : adj[i]) {
                    if(mark[it]) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        
        vector<int> nodes;
        if(flag) {
            for(int i=0;i<n;i++) nodes.push_back(i);
        } else {
            for(int i=0;i<n;i++) {
                if(!mark[i]) nodes.push_back(i);
            }
        }

        return nodes;
    }
};