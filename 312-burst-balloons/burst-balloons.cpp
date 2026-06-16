class Solution {
public:

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        reverse(nums.begin(), nums.end());

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n;i>=1;i--) {
            for(int j=i;j<=n;j++) {
                for(int k=i;k<=j;k++) {
                    dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }

        return dp[1][n];
    }
};