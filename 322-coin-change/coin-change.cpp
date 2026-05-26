class Solution {
public:
    int f(int idx, int T, vector<int>&coins, vector<vector<int>>&dp) {
        if(idx == 0) {
            if(T % coins[0] == 0) return T/coins[0];
            return 1e9;
        }
        if(dp[idx][T] != -1) return dp[idx][T];
        int notTake = f(idx-1, T, coins, dp);
        int take = INT_MAX;
        if(coins[idx] <= T) {
            take = 1 + f(idx, T-coins[idx], coins, dp);
        }
        return dp[idx][T] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, 1e9));
        
        for(int i=0;i<=amt;i++) {
            if(i % coins[0] == 0) dp[0][i] = i/coins[0];
        }

        for(int i=1;i<n;i++) {
            for(int j=0;j<=amt;j++) {
                int notTake = 0 + dp[i-1][j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(take, notTake);
            }
        }

        if(dp[n-1][amt] != 1e9) return dp[n-1][amt];
        return -1;
    }
};