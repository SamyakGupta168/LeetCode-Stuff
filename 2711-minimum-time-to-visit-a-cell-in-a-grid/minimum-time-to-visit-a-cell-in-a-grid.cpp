class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            int adjTime = INT_MAX;
            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    adjTime = min(adjTime, grid[nr][nc]);
                    if(1 + dis >= grid[nr][nc]) {
                        if(1 + dis < dist[nr][nc]) {
                            dist[nr][nc] = 1 + dis;
                            pq.push({dist[nr][nc], {nr, nc}});
                        }
                    } else if(r != 0 || c != 0) {
                        int diff = grid[nr][nc] - dis;
                        int time = 0;
                        if(diff & 1) time = dis + diff;
                        else time = dis + diff + 1;
                        if(time < dist[nr][nc]) {
                            dist[nr][nc] = time;
                            pq.push({dist[nr][nc], {nr, nc}});
                        }
                    }
                }
            }

            if(adjTime <= 1 && r == 0 && c == 0) {
                for(int i=0;i<4;i++) {
                    int nr = r + dx[i], nc = c + dy[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if(grid[nr][nc] > 1) {
                            int time = 0;
                            if(grid[nr][nc] & 1) time = grid[nr][nc];
                            else time = grid[nr][nc] + 1;
                            if(time < dist[nr][nc]) {
                                dist[nr][nc] = time;
                                pq.push({dist[nr][nc], {nr, nc}});
                            }
                        }
                    }
                }
            }
        }

        return (dist[n-1][m-1] != INT_MAX ? dist[n-1][m-1] : -1);
    }
};