class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        cost[0][0] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int cc = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(cc != cost[r][c]) continue;

            for(int i=0;i<4;i++) {
                int nr = r + dy[i], nc = c + dx[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(grid[r][c] - 1 == i) {
                    if(cc < cost[nr][nc]) {
                        cost[nr][nc] = cc;
                        pq.push({cc, {nr, nc}});
                    }
                } else {
                    if(cc + 1 < cost[nr][nc]) {
                        cost[nr][nc] = cc + 1;
                        pq.push({cc + 1, {nr, nc}});
                    }
                }
            }
        }

        return cost[n-1][m-1];
    }
};