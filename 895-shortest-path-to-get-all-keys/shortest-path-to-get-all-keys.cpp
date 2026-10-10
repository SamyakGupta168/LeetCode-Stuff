class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int k = 0, sr = -1, sc = -1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') k |= (1<<(grid[i][j]-'a'));
                if(grid[i][j] == '@') {
                    sr = i, sc = j;
                }
            }
        }

        vector<vector<vector<int>>> dp((1<<6), vector<vector<int>>(n, vector<int>(m, INT_MAX)));
        // {dist, {k, {r, c}}}
        priority_queue<pair<int,pair<int,pair<int,int>>>, vector<pair<int,pair<int,pair<int,int>>>>, greater<pair<int,pair<int,pair<int,int>>>>> pq;
        dp[0][sr][sc] = 0;
        pq.push({0, {0, {sr, sc}}});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int kk = pq.top().second.first;
            int r = pq.top().second.second.first;
            int c = pq.top().second.second.second;
            pq.pop();
            if(dis != dp[kk][r][c]) continue;

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(grid[nr][nc] == '#') continue;
                if(grid[nr][nc] == '.' || grid[nr][nc] == '@') {
                    if(dis + 1 < dp[kk][nr][nc]) {
                        dp[kk][nr][nc] = dis + 1;
                        pq.push({dp[kk][nr][nc], {kk, {nr, nc}}});
                    }
                } else if(grid[nr][nc] >= 'a' && grid[nr][nc] <= 'z') {
                    int b = grid[nr][nc] - 'a';
                    if(dis + 1 < dp[kk | (1 << b)][nr][nc]) {
                        dp[kk | (1 << b)][nr][nc] = dis + 1;
                        pq.push({dp[kk | (1 << b)][nr][nc], {kk | (1 << b), {nr, nc}}});
                    }
                } else { // A to Z
                    int b = tolower(grid[nr][nc]) - 'a';
                    if((kk&(1<<b)) && dis + 1 < dp[kk][nr][nc]) {
                        dp[kk][nr][nc] = dis + 1;
                        pq.push({dp[kk][nr][nc], {kk, {nr, nc}}});
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = min(ans, dp[k][i][j]);
            }
        }

        return (ans != INT_MAX ? ans : -1);
    }
};