class Solution {
public:
    bool f(int i, int j, string& p, string &s, vector<vector<int>>&dp) {
        if(i < 0) {
            if(j < 0) return true;
            return false;
        }
        if(j < 0) {
            if(p[i] == '*') return f(i-1, j, p, s, dp);
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?') return dp[i][j] = f(i-1, j-1, p, s, dp);
        if(p[i] == '*') return dp[i][j] = f(i-1, j, p, s, dp) | f(i, j-1, p, s, dp);
        return false;
    }

    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, p, s, dp);
    }
};