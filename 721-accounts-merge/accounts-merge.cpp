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
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mp;
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                string &mail = accounts[i][j];
                if(mp.count(mail)) {
                    ds.unionBySize(mp[mail], i);
                } else mp[mail] = i;
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto p : mp) {
            string mail = p.first;
            int acc = ds.findUPar(p.second);
            mergedMail[acc].push_back(mail);
        }

        for(auto &list : mergedMail) {
            sort(list.begin(), list.end());
        }

        vector<vector<string>> ans;
        int idx = 0;
        for(auto &list : mergedMail) {
            if(!list.empty()) {
                vector<string> acc;
                acc.push_back(accounts[idx][0]);
                for(auto &mail : list) acc.push_back(mail);
                ans.push_back(acc);
            }
            idx++;
        }

        return ans;
    }
};