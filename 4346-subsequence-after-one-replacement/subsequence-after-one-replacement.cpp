class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = 1;
        dp[0][0] = (s[0] == t[0]);
        for(int i=1;i<n;i++) {
            int idx1 = dp[i-1][1];
            if(idx1 == s.size()) {
                dp[i][1] = idx1;
            } else if(s[idx1] == t[i]) {
                dp[i][1] = idx1 + 1;
            } else {
                idx1 = max(idx1, dp[i-1][0] + 1);
                dp[i][1] = idx1;
            }

            int idx2 = dp[i-1][0];
            if(idx2 == s.size()) {
                dp[i][0] = idx2;
            } else if(s[idx2] == t[i]) {
                dp[i][0] = idx2 + 1;
            } else {
                dp[i][0] = idx2;
            }
        }

        return dp[n-1][1] == s.size();
    }
};