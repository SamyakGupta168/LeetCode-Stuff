class Solution {
public:
    using ll = long long;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(auto &v : piles) {
            for(int i=1;i<v.size();i++) v[i] += v[i-1];
        }

        int n = piles.size();
        vector<ll> dp(k+1, 0);

        for(int j=0;j<min((int)piles[0].size(), k);j++) {
            dp[j+1] = piles[0][j];
        }

        for(int i=1;i<n;i++) {
            for(int j=k;j>=1;j--) {
                for(int l=0;l<min((int)piles[i].size(), j);l++) {
                    dp[j] = max(dp[j], piles[i][l] + dp[j-l-1]);
                }
            }
        }

        return dp[k];
    }
};