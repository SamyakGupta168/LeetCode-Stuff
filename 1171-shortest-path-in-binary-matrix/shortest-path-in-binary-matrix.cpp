class Solution {
public:
    int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
    int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

    int dijkstra(vector<vector<int>>&grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        queue<pair<int, pair<int,int>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int dis = pq.front().first;
            int r = pq.front().second.first;
            int c = pq.front().second.second;
            pq.pop();

            for(int i=0;i<8;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n) {
                    if(grid[nr][nc] == 1) continue;
                    if(dis + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dis + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        
        return (dist[n-1][n-1] == INT_MAX) ? -1 : dist[n-1][n-1] + 1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        return dijkstra(grid);
    }
};