class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j*j<=i;j++) {
                dp[1][i] |= !dp[0][i - j*j];
                dp[0][i] |= !dp[1][i - j*j];
            }
        }

        return dp[1][n];
    }
};