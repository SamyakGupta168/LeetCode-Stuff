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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);
        unordered_map<int, int> rowNode, colNode;
        for(int i=0;i<n;i++) {
            int r = stones[i][0], c = stones[i][1];
            if(!rowNode.count(r)) {
                rowNode[r] = i+1;
            } else {
                ds.unionBySize(rowNode[r], i+1);
            }

            if(!colNode.count(c)) {
                colNode[c] = i+1;
            } else {
                ds.unionBySize(colNode[c], i+1);
            }
        }

        unordered_set<int> st;
        for(int i=1;i<=n;i++) {
            st.insert(ds.findUPar(i));
        }

        return n - (int)st.size();
    }
};