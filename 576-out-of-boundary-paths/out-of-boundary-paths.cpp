class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    ll f(int i, int j, int mm, int n, int m, vector<vector<vector<int>>>&dp) {
        if(i < 0 || j < 0 || i >= n || j >= m) return 1;
        if(!mm) return 0;
        if(dp[i][j][mm] != -1) return dp[i][j][mm];
        ll cnt = 0;
        for(int k=0;k<4;k++) {
            int ni = i + dx[k], nj = j + dy[k];
            cnt += f(ni, nj, mm - 1, n, m, dp);
            cnt %= mod;
        }
        return dp[i][j][mm] = cnt;
    }

    int findPaths(int n, int m, int mm, int sr, int sc) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(mm + 1, -1)));
        return (int)f(sr, sc, mm, n, m, dp);
    }
};