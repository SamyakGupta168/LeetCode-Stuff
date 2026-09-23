class Solution {
public:
    int minimumTotal(vector<vector<int>>& tt) {
        int n = tt.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = tt[0][0];
        for(int i=1;i<n;i++) {
            for(int j=0;j<=i;j++) {
                dp[i][j] = tt[i][j] + min(dp[i-1][j], (j-1 >= 0 ? dp[i-1][j-1] : INT_MAX));
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};