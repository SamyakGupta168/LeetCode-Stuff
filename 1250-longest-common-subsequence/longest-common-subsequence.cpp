class Solution {
public:
    int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>>&dp) {
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, s1, s2, dp);
        }

        return dp[idx1][idx2] = max(f(idx1-1, idx2, s1, s2, dp), f(idx1, idx2-1, s1, s2, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s1, s2, dp);
    }
};