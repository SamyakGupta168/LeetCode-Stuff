class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for(int i=0;i<n;i++) {
            dp[i][i][1] = nums[i];
            dp[i][i][0] = -nums[i];
        }

        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                dp[i][j][1] = INT_MIN, dp[i][j][0] = INT_MAX;
                
                dp[i][j][1] = max(dp[i][j][1], nums[i] + dp[i+1][j][0]);
                dp[i][j][1] = max(dp[i][j][1], nums[j] + dp[i][j-1][0]);
                dp[i][j][0] = min(dp[i][j][0], -nums[i] + dp[i+1][j][1]);
                dp[i][j][0] = min(dp[i][j][0], -nums[j] + dp[i][j-1][1]);
            }
        }

        return (dp[0][n-1][1] >= 0);        
    }
};