class Solution {
public:
    int f(int i, int j, string &s, vector<vector<int>>&dp) {
        if(i+1 == j && s[i]==s[j]) return 1;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = ((s[i]==s[j])&&f(i+1, j-1, s, dp));
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(dp[i][j] == -1) cnt += f(i, j, s, dp);
                else cnt += dp[i][j];
            }
        }

        return cnt;
    }
};