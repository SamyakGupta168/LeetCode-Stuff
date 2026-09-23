class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int mod = 1e9 + 7;
    int dp[50][50][51];

    int f(int i, int j, int moves, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return 1;
        if(moves == 0) return 0;
        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        dp[i][j][moves] = 0;
        for(int k=0;k<4;k++) {
            int r = i + dx[k], c = j + dy[k];
            dp[i][j][moves] += f(r, c, moves - 1, n, m);
            dp[i][j][moves] %= mod;
        }
        
        return dp[i][j][moves];
    }

    int findPaths(int n, int m, int mx, int sr, int sc) {
        memset(dp, -1, sizeof(dp));
        return f(sr, sc, mx, n, m);
    }
};