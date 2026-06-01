class Solution {
public:

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int i=1;i<n;i++) {
            if(s[i-1]==s[i]) dp[i-1][i] = 1;
        }

        int cnt = 0;
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i == j) {
                    cnt += dp[i][j];
                    continue;
                }
                else if(j-i == 1) {
                    cnt += dp[i][j];
                    continue;
                }

                dp[i][j] = (s[i]==s[j])&&dp[i+1][j-1];
                cnt += dp[i][j];
            }
        }

        return cnt;
    }
};