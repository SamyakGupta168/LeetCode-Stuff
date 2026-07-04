class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int no = 0;
        map<string, int> node;
        for(auto &x : equations) {
            auto &s1 = x[0];
            auto &s2 = x[1];
            if(!node.count(s1)) node[s1] = no++;
            if(!node.count(s2)) node[s2] = no++;
        }

        int n = node.size();
        // vector<vector<double>> dist(n, vector<double>(n, 1e4));
        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<equations.size();i++) {
            int u = node[equations[i][0]];
            int v = node[equations[i][1]];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }

        // for(int k=0;k<n;k++) {
        //     for(int i=0;i<n;i++) {
        //         for(int j=0;j<n;j++) {
        //             if(dist[i][k] != 1e4 && dist[k][j] != 1e4) dist[i][j] = min(dist[i][j], dist[i][k] * dist[k][j]);
        //         }
        //     }
        // }

        vector<vector<double>> dist(n, vector<double>(n, 1e4));
        for(int i=0;i<n;i++) {
            queue<pair<double,int>> q;
            vector<int> vis(n, 0);
            vis[i] = 1;
            q.push({1, i});
            dist[i][i] = 1;
            while(!q.empty()) {
                int node = q.front().second;
                double dis = q.front().first;
                q.pop();
                for(auto &it : adj[node]) {
                    int adjNode = it.first;
                    double edw = it.second;
                    if(!vis[adjNode]) {
                        vis[adjNode] = 1;
                        dist[i][adjNode] = dis * edw;
                        q.push({dist[i][adjNode], adjNode});
                    }
                }
            }
        }

        for(auto &row : dist) {
            for(auto &x : row) {
                if(x == 1e4) x = -1.0;
            }
        }

        vector<double> ans;
        for(auto &q : queries) {
            if(!node.count(q[0]) || !node.count(q[1])) {
                ans.push_back(-1);
                continue;
            }
            int u = node[q[0]];
            int v = node[q[1]];
            ans.push_back(dist[u][v]);
        }
        
        return ans;
    }
};