class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string cc) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            if(cc[u] == cc[v]) return -1;
            if((cc[u] == 'B' && cc[v] == 'W') ||
                (cc[u] == 'W' && cc[v] == 'R') || 
                (cc[u] == 'R' && cc[v] == 'B')) adj[u].push_back(v);
            else adj[v].push_back(u);
        }

        int mo = 0;
        vector<int> ind(n);
        for(auto &v : adj) {
            mo = max(mo, (int)v.size());
            for(auto x : v) ind[x]++;
        }

        if(mo > 2) return -1;

        int cnt = 0, node = -1;
        for(int i=0;i<n;i++) {
            if(!ind[i]) {
                cnt++, node = i;
            }
        }

        if(cnt != 1) return -1;
        return node;
    }
};