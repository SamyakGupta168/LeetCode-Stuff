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
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));
        int ans = f(n-1, amt, coins, dp);
        if(ans != 1e9) return ans;
        return -1;
    }
};