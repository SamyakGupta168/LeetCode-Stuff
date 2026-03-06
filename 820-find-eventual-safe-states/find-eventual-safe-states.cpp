class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>&graph) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, graph)) return true;
            } else if(pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0), pathVis(V, 0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i, vis, pathVis, graph);
            }
        }
        vector<int> nodes;
        for(int i=0;i<V;i++) {
            if((vis[i]&pathVis[i])==0) nodes.push_back(i);
        }
        return nodes;
    }
};