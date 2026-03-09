class Solution {
public:
    void topo(int V, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&ans) {
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> ans;
        topo(V, adj, indegree, ans);
        if(ans.size()<V) return {};
        return ans; 
    }
};