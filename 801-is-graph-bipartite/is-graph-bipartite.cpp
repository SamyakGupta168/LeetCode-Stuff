class Solution {
public:
    bool bfs(int src, vector<int>&vis, vector<vector<int>>&graph, vector<int>&color) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        color[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            int parentColor = color[node];
            q.pop();
            for(auto it : graph[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    color[it] = 1 - parentColor;
                    q.push(it);
                } else if(parentColor == color[it]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), color(n, -1);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(!bfs(i, vis, graph, color)) return false;
            }
        }
        return true;
    }
};