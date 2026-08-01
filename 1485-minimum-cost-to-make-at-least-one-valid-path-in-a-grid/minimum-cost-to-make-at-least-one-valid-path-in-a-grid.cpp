class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0] = 0;
        dq.push_back({0, 0});
        while(!dq.empty()) {
            int r = dq.front().first;
            int c = dq.front().second;
            int dis = dist[r][c];
            dq.pop_front();

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int d = grid[r][c] == i+1 ? dis : dis + 1;
                    if(d < dist[nr][nc]) {
                        dist[nr][nc] = d;
                        if(d == dis) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};