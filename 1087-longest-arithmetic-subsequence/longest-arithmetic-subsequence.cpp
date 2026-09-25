class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int ans = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                dp[i][nums[i]-nums[j]+500] = max(dp[i][nums[i]-nums[j]+500], 1 + dp[j][nums[i]-nums[j]+500]);
                ans = max(ans, dp[i][nums[i]-nums[j]+500]);
            }
        }

        return ans;
    }
};