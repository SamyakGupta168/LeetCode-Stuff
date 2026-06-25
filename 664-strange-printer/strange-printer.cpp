class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, string &t) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minTurns = 1 + f(i+1, j, dp, t);

        for(int k=i+1;k<=j;k++) {
            if(t[i] == t[k]) {
                minTurns = min(minTurns, f(i, k-1, dp, t) + f(k+1, j, dp, t));
            }
        }
        return dp[i][j] = minTurns;
    }

    int strangePrinter(string s) {
        string t;
        t += s[0];
        for(int i=1;i<s.size();i++) {
            if(s[i] != s[i-1]) {
                t += s[i];
            }
        }

        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, dp, t);
    }
};