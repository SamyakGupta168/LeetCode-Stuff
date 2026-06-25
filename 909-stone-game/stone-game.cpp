class Solution {
public:

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

        for(int i=0;i<n;i++) {
            dp[i][i][1] = piles[i];
            dp[i][i][0] = -piles[i];
        }

        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                dp[i][j][1] = max(dp[i][j][1], piles[i] + dp[i+1][j][0]);
                dp[i][j][1] = max(dp[i][j][1], piles[j] + dp[i][j-1][0]);
                dp[i][j][0] = max(dp[i][j][0], -piles[i] + dp[i+1][j][1]);
                dp[i][j][0] = max(dp[i][j][0], -piles[j] + dp[i][j-1][1]);
            }
        }

        return (dp[0][n-1][1] > 0);
    }
};