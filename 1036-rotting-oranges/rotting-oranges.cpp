class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void bfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int &time) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            auto [x, y] = node.first;
            time = max(time, node.second);
            q.pop();
            for(int i=0;i<4;i++) {
                int nr=x+dx[i], nc=y+dy[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    if(grid[nr][nc]==1 && !vis[nr][nc]) {
                        vis[nr][nc]=2;
                        q.push({{nr, nc}, node.second+1});
                    }
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int time=0;
        bfs(grid, vis, time);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && vis[i][j]==0) return -1; 
            }
        }
        return time;
    }
};