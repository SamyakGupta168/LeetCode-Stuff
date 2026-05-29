class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int f(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp, int n, int m) {
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = 1;
        for(int k=0;k<4;k++) {
            int ni = i + dy[k], nj = j + dx[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m) {
                if(mat[i][j] < mat[ni][nj]) {
                    maxi = max(maxi, 1 + f(ni, nj, mat, dp, n, m));
                }
            }
        }

        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j] == -1) {
                    ans = max(ans, f(i, j, mat, dp, n, m));
                }
            }
        }

        return ans;
    }
};