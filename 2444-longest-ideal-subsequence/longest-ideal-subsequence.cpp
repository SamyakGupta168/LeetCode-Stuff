class Solution {
public:
    int f(int i, int ch, string &s, int k, vector<vector<int>>&dp) {
        int n = s.size();
        if(i >= n) return 0;
        if(dp[i][ch] != -1) return dp[i][ch];
        if(ch == 0) {
            int notTake = f(i+1, ch, s, k, dp);
            int take = 1 + f(i+1, s[i] - 'a' + 1, s, k, dp);
            return dp[i][ch] = max(take, notTake);
        }

        int notTake = f(i+1, ch, s, k, dp);
        int take = 0;
        int chNo = s[i] - 'a';
        if(abs(chNo - ch + 1) <= k) {
            take = 1 + f(i+1, s[i] - 'a' + 1, s, k, dp);
        }
        return dp[i][ch] = max(take, notTake);
    }

    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return f(0, 0, s, k, dp);
    }
};