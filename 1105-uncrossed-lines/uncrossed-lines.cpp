class Solution {
public:
    int f(int i, int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp) {
        int n = nums1.size(), m = nums2.size();
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int notTake = f(i, j+1, nums1, nums2, dp);
        int take = 0;
        for(int k=i;k<n;k++) {
            if(nums2[j] == nums1[k]) {
                take = 1 + f(k+1, j+1, nums1, nums2, dp);
                break;
            }
        }
        return dp[i][j] = max(take, notTake);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
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