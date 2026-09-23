class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));

        for(int i=0;i<n;i++) dp[0][i] = mat[0][i];

        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[1][j] = min(dp[1][j], dp[0][j]);
                if(j-1 >= 0) dp[1][j] = min(dp[1][j], dp[0][j-1]);
                if(j+1 < n) dp[1][j] = min(dp[1][j], dp[0][j+1]);
                dp[1][j] += mat[i][j];
            }
            dp[0] = dp[1];
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};