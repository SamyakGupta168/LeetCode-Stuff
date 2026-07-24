class Solution {
public:
    using ll = long long;
    ll f(int i, int k, vector<vector<int>>&piles, vector<vector<ll>>&dp) {
        if(k == 0) return 0;
        if(i == 0) {
            if(piles[0].size() >= k) return piles[0][k-1];
            return -2e9;
        }
        if(dp[i][k] != -1) return dp[i][k];
        ll maxSum = f(i-1, k, piles, dp);
        for(int j=0;j<min((int)piles[i].size(), k);j++) {
            maxSum = max(maxSum, piles[i][j] + f(i-1, k-j-1, piles, dp));
        }
        return dp[i][k] = maxSum;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(auto &v : piles) {
            for(int i=1;i<v.size();i++) v[i] += v[i-1];
        }
        int n = piles.size();
        vector<vector<ll>> dp(n, vector<ll>(k+1, -1));
        return (int)f(n-1, k, piles, dp);
    }
};