class Solution {
public:
    int f(int i, int flag, vector<vector<int>>&dp, string &s, string &t) {
        if(i == 0) {
            if(flag) return 1;
            else return s[0] == t[0];
        }
        if(dp[i][flag] != -1) return dp[i][flag];

        if(flag) {
            int idx = f(i-1, 1, dp, s, t);
            if(s[idx] == t[i]) return dp[i][1] = idx + 1;
            idx = max(idx, f(i-1, 0, dp, s, t) + 1);
            return dp[i][1] = idx;
        } else {
            int idx = f(i-1, 0, dp, s, t);
            if(s[idx] == t[i]) return dp[i][0] = idx + 1;
            return dp[i][0] = idx;
        }

        return -1;
    }

    bool canMakeSubsequence(string s, string t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int idx1 = f(n-1, 1, dp, s, t);
        int idx2 = f(n-1, 0, dp, s, t);
        return idx1 == s.size() || idx2 == s.size();
    }
};