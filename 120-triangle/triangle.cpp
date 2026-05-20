class Solution {
public:
    int f(int r, int i, vector<vector<int>>&dp, vector<vector<int>>&tr, int n) {
        if(r >= n) return 0;
        if(dp[r][i] != 1e8) return dp[r][i];
        dp[r][i] = min(f(r+1, i, dp, tr, n), f(r+1, i+1, dp, tr, n));
        return dp[r][i] += tr[r][i];
    }

    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        return f(0, 0, dp, tr, n);
    }
};