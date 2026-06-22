class Solution {
public:
    using ld = long double;

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<ld> dp(m+1, 0);
        dp[0] = 1;

        for(int i=1;i<=n;i++) {
            for(int j=m;j>=1;j--) {
                ld notTake = dp[j];
                ld take = 0;
                if(s[i-1] == t[j-1]) {
                    take = dp[j-1];
                }
                dp[j] = take + notTake;
            }
        }

        return (int)dp[m];
    }
};