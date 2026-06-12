class Solution {
public:
    bool bfs(int src, vector<int>&vis, vector<vector<int>>&graph) {
        queue<int> q;
        q.push(src);
        vis[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            int parentColor = vis[node];
            q.pop();
            for(auto it : graph[node]) {
                if(vis[it] == -1) {
                    vis[it] = 1 - parentColor;
                    q.push(it);
                } else if(parentColor == vis[it]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i=0;i<n;i++) {
            if(vis[i] == -1) {
                if(!bfs(i, vis, graph)) return false;
            }
        }
        return true;
    }
};