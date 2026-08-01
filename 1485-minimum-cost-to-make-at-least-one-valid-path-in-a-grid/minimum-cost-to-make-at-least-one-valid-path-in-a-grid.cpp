class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        queue<pair<int, pair<int,int>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int dis = pq.front().first;
            int r = pq.front().second.first;
            int c = pq.front().second.second;
            pq.pop();

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int d = grid[r][c] == i+1 ? dis : dis + 1;
                    if(d < dist[nr][nc]) {
                        dist[nr][nc] = d;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};