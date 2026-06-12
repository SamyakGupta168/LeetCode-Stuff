class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&heights) {
        int n = heights.size(), m = heights[0].size();
        vis[r][c] = 1;
        for(int i=0;i<4;i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                if(heights[nr][nc] >= heights[r][c] && !vis[nr][nc]) {
                    dfs(nr, nc, vis, heights);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        // Pacific Ocean
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        for(int i=0;i<m;i++) {
            if(!vis1[0][i]) dfs(0, i, vis1, heights);
        }

        for(int i=1;i<n;i++) {
            if(!vis1[i][0]) dfs(i, 0, vis1, heights);
        }

        // Atlantic Ocean
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        for(int i=0;i<m;i++) {
            if(!vis2[n-1][i]) dfs(n-1, i, vis2, heights);
        }

        for(int i=0;i<n-1;i++) {
            if(!vis2[i][m-1]) dfs(i, m-1, vis2, heights);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis1[i][j] && vis2[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};