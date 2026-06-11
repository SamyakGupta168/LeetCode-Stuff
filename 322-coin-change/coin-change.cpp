class Solution {
public:
    int f(int i, int amt, vector<int>&coins, vector<vector<int>>&dp) {
        int n = coins.size();
        if(amt == 0) return 0;
        if(i == n) return 1e9;
        if(dp[i][amt] != -1) return dp[i][amt];
        int notTake = f(i+1, amt, coins, dp);
        int take = INT_MAX;
        if(amt >= coins[i]) {
            take = 1 + f(i, amt - coins[i], coins, dp);
        }

        return dp[i][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));
        int ans = f(0, amt, coins, dp);
        return (ans != 1e9 ? ans : -1);
    }
};