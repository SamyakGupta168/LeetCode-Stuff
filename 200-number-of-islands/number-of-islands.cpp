class DisjointSet {
    vector<int> rank, parent, size;
    public:
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
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DisjointSet ds(n*m);
        for(int r=0;r<n;r++) {
            for(int c=0;c<m;c++) {
                if(grid[r][c] == '0') continue;
                int node = r*m + c;
                for(int i=0;i<4;i++) {
                    int nr = r + dx[i], nc = c + dy[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if(grid[nr][nc] == '1') {
                            int adjNode = nr*m + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        unordered_set<int> st;
        for(int node=0;node<n*m;node++) {
            int parent = ds.findUPar(node);
            int r = parent / m, c = parent % m;
            if(grid[r][c] == '1') st.insert(parent);
        }

        return (int)st.size();
    }
};