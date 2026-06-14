class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp) {
        int n = s1.size(), m = s2.size();
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(i+1, j+1, s1, s2, dp);
        }
        return dp[i][j] = max(f(i+1, j, s1, s2, dp), f(i, j+1, s1, s2, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, s1, s2, dp);
    }
};