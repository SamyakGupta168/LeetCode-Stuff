class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        // {obs, {dist, node}}
        priority_queue<pair<int, pair<int,pair<int,int>>>, vector<pair<int, pair<int,pair<int,int>>>>, greater<pair<int, pair<int,pair<int,int>>>>> pq;
        pq.push({0, {0, {0, 0}}});
        
        while(!pq.empty()) {
            int obs = pq.top().first;
            int dis = pq.top().second.first;
            int r = pq.top().second.second.first;
            int c = pq.top().second.second.second;
            pq.pop();
            if(obs > k || (r == n-1 && c == m-1)) continue;
            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if(dis + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dis + 1;
                        if(grid[nr][nc]) pq.push({obs+1, {dist[nr][nc], {nr, nc}}});
                        else pq.push({obs, {dist[nr][nc], {nr, nc}}});
                    }
                }
            }
        }

        return (dist[n-1][m-1] != INT_MAX ? dist[n-1][m-1] : -1);
    }
};