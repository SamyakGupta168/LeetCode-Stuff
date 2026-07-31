class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int cnt = pq.top().first;
            int dis = pq.top().second.first;
            int node = pq.top().second.second;
            int r = node / m;
            int c = node % m;
            pq.pop();

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if(1 + dis < dist[nr][nc]) {
                        int newCnt = (grid[nr][nc] == 1 ? cnt + 1 : cnt);
                        int adjNode = nr * m + nc;
                        if(newCnt <= k) {
                            dist[nr][nc] = 1 + dis;
                            pq.push({newCnt, {dist[nr][nc], adjNode}});
                        }
                    }
                }
            }
        }

        return (dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1]);
    }
};