class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vis[r][c] = 1;
        for(int i=0;i<4;i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m) {
                if(!vis[nr][nc] && grid[nr][nc] == '1') dfs(nr, nc, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};