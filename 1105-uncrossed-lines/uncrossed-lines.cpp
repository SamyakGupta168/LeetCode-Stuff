class Solution {
public:

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        unordered_map<int,int> idx;
        for(int i=n-1;i>=0;i--) {
            idx[nums1[i]] = i;
            for(int j=m-1;j>=0;j--) {
                int notTake = dp[i][j+1];
                int take = 0;
                if(idx.count(nums2[j])) {
                    int k = idx[nums2[j]];
                    take = 1 + dp[k+1][j+1];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};