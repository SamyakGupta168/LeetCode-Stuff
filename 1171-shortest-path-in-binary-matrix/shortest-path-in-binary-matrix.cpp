class Solution {
public:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    void dijkstra(auto src, vector<vector<int>>&grid, vector<vector<int>>&dist) {
        int n=grid.size(), m=grid[0].size();
        dist[src.first][src.second] = 1;
        // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({1, src});
        
        while(!pq.empty()) {
            int dis = pq.front().first;
            auto [x, y] = pq.front().second;
            pq.pop();
            
            for(int i=0;i<8;i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m) {
                    if(grid[nx][ny] == 1) {
                        if(dis + 1 < dist[nx][ny]) {
                            dist[nx][ny] = dis + 1;
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        auto src = make_pair(0, 0);
        auto desti = make_pair(n-1, m-1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) grid[i][j] = 1 - grid[i][j];
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        dijkstra(src, grid, dist);
        if(dist[desti.first][desti.second] == INT_MAX) return -1;
        return dist[desti.first][desti.second];
    }
};