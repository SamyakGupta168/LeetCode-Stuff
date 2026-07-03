class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    pq.push({0, {i, j}});
                }
            }
        }

        while(!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if(dis + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dis + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        priority_queue<pair<int, pair<int,int>>> pq1;
        vector<vector<int>> cost(n, vector<int>(m, INT_MIN));
        pq1.push({dist[0][0], {0, 0}});
        cost[0][0] = dist[0][0];
        while(!pq1.empty()) {
            int cst = pq1.top().first;
            int r = pq1.top().second.first;
            int c = pq1.top().second.second;
            pq1.pop();
            if(r == n-1 && c == m-1) return cst;

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newCost = min(cst, dist[nr][nc]);
                    if(newCost > cost[nr][nc]) {
                        cost[nr][nc] = newCost;
                        pq1.push({cost[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};