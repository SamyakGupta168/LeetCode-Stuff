class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    ll f(int i, int k, int n, vector<vector<ll>>&dp) {
        if(i < 0 || i >= n) return 0;
        if(k == 0) return (i == 0);
        if(dp[i][k] != -1) return dp[i][k];
        dp[i][k] = f(i-1, k-1, n, dp);
        dp[i][k] %= mod;
        dp[i][k] += f(i, k-1, n, dp);
        dp[i][k] %= mod;
        dp[i][k] += f(i+1, k-1, n, dp);
        dp[i][k] %= mod;
        return dp[i][k];
    }

    int numWays(int steps, int n) {
        n = min(n, steps+1);
        vector<vector<ll>> dp(n, vector<ll>(steps+1, -1));
        return f(0, steps, n, dp);
    }
};