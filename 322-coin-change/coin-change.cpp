class Solution {
public:

    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amt+1, 0));
        
        for(int i=1;i<=amt;i++) dp[n][i] = 1e9;

        for(int i=n-1;i>=0;i--) {
            for(int j=1;j<=amt;j++) {
                int notTake = dp[i+1][j];
                int take = INT_MAX;
                if(j >= coins[i]) take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, notTake);
                if(dp[i][j] == 1e9) dp[i][j] = 1e9;
            }
        }

        return (dp[0][amt] != 1e9 ? dp[0][amt] : -1);
    }
};