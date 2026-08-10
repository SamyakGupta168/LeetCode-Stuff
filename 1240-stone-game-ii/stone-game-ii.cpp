class Solution {
public:
    int dp[2][102][102];

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, 0, sizeof(dp));
        for(int i=n-1;i>=0;i--) {
            for(int j=n;j>=1;j--) {
                dp[1][i][j] = INT_MIN;
                dp[0][i][j] = INT_MAX;
                int stones = 0;
                for(int x=1;x<=min(2*j, n-i);x++) {
                    int idx = i + x - 1;
                    stones += piles[idx];
                    dp[1][i][j] = max(dp[1][i][j], stones + dp[0][idx+1][max(x, j)]);
                    dp[0][i][j] = min(dp[0][i][j], dp[1][idx+1][max(x, j)]);
                }
            }
        }

        return dp[1][0][1];
    }
};