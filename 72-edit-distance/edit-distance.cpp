class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, string &s1, string &s2) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        if(s1[i] == s2[j]) {
            mini = min(mini, f(i-1, j-1, dp, s1, s2));
        }
        
        mini = min(mini, 1 + f(i, j-1, dp, s1, s2));
        mini = min(mini, 1 + f(i-1, j, dp, s1, s2));
        mini = min(mini, 1 + f(i-1, j-1, dp, s1, s2));
        return dp[i][j] = mini;
    }

    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, dp, s1, s2);
    }
};