class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        int ans = 2;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int diff = nums[j] - nums[i];
                dp[j][diff+500] = max(dp[j][diff+500], 1 + dp[i][diff+500]);
                ans = max(ans, dp[j][diff+500]);
            }
        }

        return ans;
    }
};