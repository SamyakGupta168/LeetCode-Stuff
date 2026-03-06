class Solution {
public:
    int dx[8] = {0, 0, 1, -1};
    int dy[8] = {1, -1, 0, 0};
    
    void bfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis) {
        int n=grid.size(), m=grid[0].size();
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r, c});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nr=x+dx[i], nc=y+dy[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    if(grid[nr][nc]=='1' && !vis[nr][nc]) {
                        vis[nr][nc]=1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis) {
        int n=grid.size(), m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++) {
            int nr=r+dy[i], nc=c+dx[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m) {
                if(grid[nr][nc]=='1' && !vis[nr][nc]) {
                    dfs(nr, nc, grid, vis);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};