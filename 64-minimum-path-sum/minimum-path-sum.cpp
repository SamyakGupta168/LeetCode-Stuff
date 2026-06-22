class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid) {
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = grid[i][j] + min(f(i-1, j, dp, grid), f(i, j-1, dp, grid));
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, dp, grid);
    }
};