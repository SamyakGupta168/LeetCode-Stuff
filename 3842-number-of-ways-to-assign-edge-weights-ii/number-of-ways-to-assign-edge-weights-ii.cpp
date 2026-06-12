class BinaryLifting {
        int n, LOG;
        vector<vector<int>> up;
        vector<int> depth;
        vector<vector<int>> adj;

        public: 
        BinaryLifting(int n, vector<vector<int>>& edges) {
            this->n = n;

            LOG = 1;
            while ((1 << LOG) <= n)
                LOG++;

            adj.resize(n + 1);

            for (auto& e : edges) {
                int u = e[0];
                int v = e[1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            up.assign(n + 1, vector<int>(LOG, 0));
            depth.assign(n + 1, 0);

            dfs(1, 0);
        }

        void dfs(int node, int parent) {
            up[node][0] = parent;

            for (int j = 1; j < LOG; j++) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }

            for (int child : adj[node]) {
                if (child == parent)
                    continue;

                depth[child] = depth[node] + 1;
                dfs(child, node);
            }
        }

        int lca(int u, int v) {

            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = LOG - 1; j >= 0; j--) {
                if (diff & (1 << j))
                    u = up[u][j];
            }

            if (u == v)
                return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        }

        int distance(int u, int v) {
            int L = lca(u, v);

            return depth[u] + depth[v] - 2 * depth[L];
        }
    };

class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& qr) {
        int n = edges.size() + 1;

        vector<int> p(n, 1);
        for (int i = 2; i < n; i++) p[i] = (2 * p[i - 1]) % mod;

        BinaryLifting bl(n, edges);
        vector<int> ans;

        for(auto &x : qr) {
            int u = x[0], v = x[1];
            if(u == v) {
                ans.push_back(0);
                continue;
            }
            int e = bl.distance(u, v);
            ans.push_back(p[e]);
        }

        return ans;

    }
};