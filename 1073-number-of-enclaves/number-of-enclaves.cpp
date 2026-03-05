class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&vis) {
        int n=grid.size(), m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m) {
                if(!vis[nr][nc] && grid[nr][nc]==1) {
                    dfs(nr, nc, grid, vis);
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            if(!vis[i][0] && grid[i][0]==1) {
                dfs(i, 0, grid, vis);
            }
        }
        for(int i=0;i<n;i++) {
            if(!vis[i][m-1] && grid[i][m-1]==1) {
                dfs(i, m-1, grid, vis);
            }
        }
        for(int i=0;i<m;i++) {
            if(!vis[0][i] && grid[0][i]==1) {
                dfs(0, i, grid, vis);
            }
        }
        for(int i=0;i<m;i++) {
            if(!vis[n-1][i] && grid[n-1][i]==1) {
                dfs(n-1, i, grid, vis);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};