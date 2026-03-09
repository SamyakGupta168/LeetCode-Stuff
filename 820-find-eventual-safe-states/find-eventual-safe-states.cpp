class Solution {
public:
    void topo(int V, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&safeNodes) {
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++) {
            for(auto x : graph[i]) {
                adj[x].push_back(i);
            } 
        }

        vector<int> indegree(V, 0);
        for(auto &v : adj) {
            for(auto x : v) {
                indegree[x]++;
            }
        }
        vector<int> safeNodes;
        topo(V, adj, indegree, safeNodes);
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};