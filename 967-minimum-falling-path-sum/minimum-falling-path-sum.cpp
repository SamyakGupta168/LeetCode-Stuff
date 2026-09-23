class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for(int i=0;i<n;i++) dp[0][i] = mat[0][i];

        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if(j+1 < n) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j] += mat[i][j];
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};