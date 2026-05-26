class Solution {
public:
    int f(int idx, int T, vector<vector<int>>&dp, vector<int>&coins) {
        if(T == 0) return 1;
        if(idx == 0) {
            return (T%coins[0] == 0);
        }
        if(dp[idx][T] != -1) return dp[idx][T];
        int notTake = f(idx-1, T, dp, coins);
        int take = 0;
        if(coins[idx] <= T) {
            take = f(idx, T - coins[idx], dp, coins);
        }
        return dp[idx][T] = take + notTake;
    }

    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));
        return f(n-1, amt, dp, coins);
    }
};