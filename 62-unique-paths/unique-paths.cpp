class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i-1, j, dp, n, m) + f(i, j-1, dp, n, m);
    }

    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, dp, n, m);
    }
};