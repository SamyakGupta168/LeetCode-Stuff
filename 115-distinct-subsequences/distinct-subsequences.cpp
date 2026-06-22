class Solution {
public:
    using ld = long double;

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<ld>> dp(n+1, vector<ld>(m+1, 0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                ld notTake = dp[i-1][j];
                ld take = 0;
                if(s[i-1] == t[j-1]) {
                    take = dp[i-1][j-1];
                }
                dp[i][j] = take + notTake;
            }
        }

        return (int)dp[n][m];
    }
};