class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k+1, INT_MAX)));
        dist[0][0][0] = 0;
        priority_queue<pair<int, pair<int, pair<int,int>>>, vector<pair<int, pair<int, pair<int,int>>>>, greater<pair<int, pair<int, pair<int,int>>>>> pq;
        // {dist, {k, {row, column}}}
        pq.push({0, {0, {0, 0}}});
        int ans = INT_MAX;
        while(!pq.empty()) {
            int dis = pq.top().first;
            int obs = pq.top().second.first;
            int r = pq.top().second.second.first;
            int c = pq.top().second.second.second;
            pq.pop();
            
            if(obs > k) continue;
            if(r == n-1 && c == m-1) {
                ans = min(ans, dis);
                continue;
            }

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if(grid[nr][nc] == 1) {
                        if(obs == k) continue;
                        if(dis + 1 < dist[nr][nc][obs+1]) {
                            dist[nr][nc][obs+1] = dis + 1;
                            pq.push({dis+1, {obs+1, {nr, nc}}});
                        }
                    } else {
                        if(dis + 1 < dist[nr][nc][obs]) {
                            dist[nr][nc][obs] = dis + 1;
                            pq.push({dis+1, {obs, {nr, nc}}});
                        }
                    }
                }
            }
        }

        return (ans != INT_MAX ? ans : -1);
    }
};