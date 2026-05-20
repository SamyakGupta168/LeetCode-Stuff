class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid, int n, int m) {
        if(i == 0 && j == 0) return grid[0][0];
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1e8;
        if(i-1 >= 0) dp[i][j] = min(dp[i][j], f(i-1, j, dp, grid, n, m));
        if(j-1 >= 0) dp[i][j] = min(dp[i][j], f(i, j-1, dp, grid, n, m));
        return dp[i][j] += grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, dp, grid, n, m);
    }
};