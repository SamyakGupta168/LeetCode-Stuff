class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = f(i-1, j, dp, grid, n, m) + f(i, j-1, dp, grid, n, m);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0) continue;
                dp[i][j] = 0;
                if(i-1 >= 0) dp[i][j] += dp[i-1][j];
                if(j-1 >= 0) dp[i][j] += dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};