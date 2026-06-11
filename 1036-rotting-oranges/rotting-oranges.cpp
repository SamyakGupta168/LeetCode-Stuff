class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while(!q.empty()) {
            time++;
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0;j<4;j++) {
                    int nr = r + dx[j], nc = c + dy[j];
                    if(nr>=0 && nc>=0 && nr<n && nc<m) {
                        if(!vis[nr][nc] && grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return max(0, time - 1);
    }
};