class Solution {
public:
    int mod = 1e9 + 7;
    int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};


    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ways = 1;
        for(int k=0;k<4;k++) {
            int ni = i + dy[k], nj = j + dx[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m) {
                if(grid[i][j]<grid[ni][nj]) ways = mod_add(ways, f(ni, nj, grid, dp, n, m), mod);
            }
        }

        return dp[i][j] = ways;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j] == -1) {
                    ans = mod_add(ans, f(i, j, grid, dp, n, m), mod);
                } else {
                    ans = mod_add(ans, dp[i][j], mod);
                }
            }
        }

        return ans;
    }
};