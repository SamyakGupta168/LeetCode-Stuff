class Solution {
public:
    using ll = long long;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(auto &v : piles) {
            for(int i=1;i<v.size();i++) v[i] += v[i-1];
        }

        int n = piles.size();
        vector<vector<ll>> dp(n, vector<ll>(k+1, 0));

        // for(int i=0;i<n;i++) dp[i][0] = 0;

        for(int j=0;j<min((int)piles[0].size(), k);j++) {
            dp[0][j+1] = piles[0][j];
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<=k;j++) {
                ll maxSum = dp[i-1][j];
                for(int l=0;l<min((int)piles[i].size(), j);l++) {
                    maxSum = max(maxSum, piles[i][l] + dp[i-1][j-l-1]);
                }
                dp[i][j] = maxSum;
            }
        }

        return dp[n-1][k];
    }
};