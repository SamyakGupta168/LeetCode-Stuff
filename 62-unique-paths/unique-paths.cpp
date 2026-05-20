class Solution {
public:
    
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 && j == 0) continue;
                dp[i][j] = 0;
                if(i-1 >= 0) dp[i][j] += dp[i-1][j];
                if(j-1 >= 0) dp[i][j] += dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};