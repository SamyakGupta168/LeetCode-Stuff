class DisjointSet {
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    int node = n*i + j;
                    for(int k=0;k<4;k++) {
                        int nr = i + dx[k], nc = j + dy[k];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n) {
                            if(grid[nr][nc] == 1) {
                                int adjNode = nr*n + nc;
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }
                    ans = max(ans, ds.size[ds.findUPar(node)]); 
                }
            }
        }



        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) {
                    set<int> st;
                    for(int k=0;k<4;k++) {
                        int nr = i + dx[k], nc = j + dy[k];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n) {
                            if(grid[nr][nc] == 1) {
                                int adjNode = nr*n + nc;
                                st.insert(ds.findUPar(adjNode));
                            }
                        } 
                    }

                    int cnt = 1;
                    for(auto x : st) cnt += ds.size[x];
                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};