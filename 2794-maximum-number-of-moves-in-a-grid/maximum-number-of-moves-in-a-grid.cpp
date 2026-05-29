class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int cnt = 1;
        if(i-1>=0 && j+1<m && grid[i][j] < grid[i-1][j+1]) cnt = max(cnt, 1 + f(i-1, j+1, grid, dp, n, m));
        if(j+1<m && grid[i][j] < grid[i][j+1]) cnt = max(cnt, 1 + f(i, j+1, grid, dp, n, m));
        if(i+1<n && j+1<m && grid[i][j] < grid[i+1][j+1]) cnt = max(cnt, 1 + f(i+1, j+1, grid, dp, n, m));
        return dp[i][j] = cnt;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans, f(i, 0, grid, dp, n, m));
        }

        return ans - 1;
    }
};