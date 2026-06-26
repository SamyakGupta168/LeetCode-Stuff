class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        for(int i=0;i<n;i++) {
            if(!vis[i]) return false;
        }

        return true;
    }
};