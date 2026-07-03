class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int,pair<int,int>>> pq;
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()) {
            int dis = pq.front().first;
            int r = pq.front().second.first;
            int c = pq.front().second.second;
            pq.pop();
            
            if(dis > health) continue;

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if(dis + grid[nr][nc] < dist[nr][nc]) {
                        dist[nr][nc] = dis + grid[nr][nc];
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return (dist[n-1][m-1] < health);
    }
};