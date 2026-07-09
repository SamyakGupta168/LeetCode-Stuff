class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            int last = dp[0];
            for (int j = 1; j <= m; j++)
            {
                int tmp = dp[j];

                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = last + 1;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                last = tmp;
            }
        }
        
        return dp.back();
    }
};