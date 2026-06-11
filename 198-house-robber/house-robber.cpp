class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1;i>=0;i--) {
            int notTake = dp[i+1][1];
            int take = nums[i] + dp[i+1][0];
            dp[i][0] = notTake;
            dp[i][1] = max(take, notTake);
        }

        return dp[0][1];
    }
};