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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        map<pair<int,int>, int> node;
        map<int, vector<int>> row, col;
        int nodeNo = 0;
        for(auto &v : stones) {
            node[{v[0], v[1]}] = nodeNo;
            nodeNo++;
            row[v[1]].push_back(v[0]);
            col[v[0]].push_back(v[1]);
        }

        DisjointSet ds(n);
        for(auto p : row) {
            int c = p.first;
            int prevRow = -1;
            for(auto r : p.second) {
                if(prevRow != -1) {
                    ds.unionBySize(node[{prevRow, c}], node[{r, c}]);
                }
                prevRow = r;
            }
        }

        for(auto p : col) {
            int r = p.first;
            int prevCol = -1;
            for(auto c : p.second) {
                if(prevCol != -1) {
                    ds.unionBySize(node[{r, prevCol}], node[{r, c}]);
                }
                prevCol = c;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i] == i) ans += ds.size[i] - 1;
        }

        return ans;
    }
};