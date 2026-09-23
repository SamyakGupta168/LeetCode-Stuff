class Solution {
public:
    int minimumTotal(vector<vector<int>>& tt) {
        int n = tt.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        dp[0][0] = tt[0][0];
        for(int i=1;i<n;i++) {
            for(int j=0;j<=i;j++) {
                dp[1][j] = tt[i][j] + min(dp[0][j], (j-1 >= 0 ? dp[0][j-1] : INT_MAX));
            }
            dp[0] = dp[1];
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};