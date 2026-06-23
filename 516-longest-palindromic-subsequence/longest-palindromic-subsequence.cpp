class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        }
        int maxi = f(i-1, j, s1, s2, dp);
        maxi = max(maxi, f(i, j-1, s1, s2, dp));
        return dp[i][j] = maxi;
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n-1, n-1, s, t, dp);
    }
};