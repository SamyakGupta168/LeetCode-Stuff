class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(27, 0));
        for(int i=n-1;i>=0;i--) {
            for(int ch=0;ch<=26;ch++) {
                if(ch == 0) {
                    int notTake = dp[i+1][ch];
                    int take = 1 + dp[i+1][s[i] - 'a' + 1];
                    dp[i][ch] = max(take, notTake);
                    continue;
                }

                int notTake = dp[i+1][ch];
                int take = 0;
                int chNo = s[i] - 'a';
                if(abs(chNo - ch + 1) <= k) {
                    take = 1 + dp[i+1][s[i] - 'a' + 1];
                }
                dp[i][ch] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};