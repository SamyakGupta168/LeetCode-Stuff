class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for(int i=1;i<n;i++) {
            int sum1 = -1, sum2 = -1;
            sum1 = nums[i] + ((i > 1) ? dp[i-2] : 0);
            sum2 = dp[i-1];
            dp[i] = max(sum1, sum2);
        }

        return dp[n-1];
    }
};