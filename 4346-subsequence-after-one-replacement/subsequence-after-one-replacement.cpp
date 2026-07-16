class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(m, vector<int>(2, 0));
        dp[0][0] = (s[0] == t[0]);
        dp[0][1] = 1;
        int ans = max(dp[0][0], dp[0][1]);
        for(int i=1;i<m;i++) {
            int idx1 = dp[i-1][0];
            if(idx1 < n && t[i] == s[idx1]) dp[i][0] = 1 + dp[i-1][0];
            else dp[i][0] = dp[i-1][0];

            if(dp[i-1][0] != n) dp[i][1] = 1 + dp[i-1][0];
            if(dp[i-1][1] < n ) {
                int idx2 = dp[i-1][1];
                if(t[i] == s[idx2]) dp[i][1] = max(dp[i][1], 1 + dp[i-1][1]);
                else dp[i][1] = max(dp[i][1], dp[i-1][0]);
            }
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        cout<<ans<<'\n';
        return ans == n;
    }
};