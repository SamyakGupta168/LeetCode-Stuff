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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int V = accounts.size();
        DisjointSet ds(V);
        
        map<string,int> node;
        int idx = 0;
        for(auto &v : accounts) {
            for(int i=1;i<v.size();i++) {
                if(!node.count(v[i])) {
                    node[v[i]] = idx;
                } else {
                    ds.unionByRank(idx, node[v[i]]);
                }
            }
            idx++;
        }
        
        vector<vector<string>> res(V);
        for(auto p : node) {
            string str = p.first;
            int curr = p.second;
            int ulp = ds.findUPar(curr);
            res[ulp].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<V;i++) {
            if(res[i].empty()) continue;
            vector<string> temp;
            sort(res[i].begin(), res[i].end());
            temp.push_back(accounts[i][0]);
            for(auto &s : res[i]) {
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};