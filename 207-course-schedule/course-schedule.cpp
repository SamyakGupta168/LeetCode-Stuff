class Solution {
public:
    void topo(int V, vector<vector<int>>&adj, vector<int>&indegree, int &cnt) {
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        for(auto &v : prerequisites) {
            adj[v[1]].push_back(v[0]);
        }

        vector<int> indegree(V, 0);
        for(auto &v : adj) {
            for(auto x : v) {
                indegree[x]++;
            }
        }

        int cnt = 0;
        topo(V, adj, indegree, cnt);
        return (cnt==V);
    }
};