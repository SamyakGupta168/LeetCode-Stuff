class Solution {
public:

    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        for(int i=0;i<n;i++) {
            dp[n-1][i] = tr[n-1][i];
        }

        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                dp[i][j] = tr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};