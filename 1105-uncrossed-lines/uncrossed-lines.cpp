class Solution {
public:

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=m-1;j>=0;j--) {
            for(int i=n-1;i>=0;i--) {
                int notTake = dp[i][j+1];
                int take = 0;
                for(int k=i;k<n;k++) {
                    if(nums2[j] == nums1[k]) {
                        take = 1 + dp[k+1][j+1];
                        break;
                    }
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};