class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(2, vector<int>(m));
        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 || j == 0) {
                    dp[1][j] = (nums1[i] == nums2[j]);
                    ans = max(ans, dp[1][j]);
                    continue;
                }
                if(nums1[i] == nums2[j]) {
                    dp[1][j] = max(dp[1][j], 1 + dp[0][j-1]);
                    ans = max(ans, dp[1][j]);
                }
            }
            dp[0] = dp[1];
            fill(dp[1].begin(), dp[1].end(), 0);
        }

        return ans;
    }
};