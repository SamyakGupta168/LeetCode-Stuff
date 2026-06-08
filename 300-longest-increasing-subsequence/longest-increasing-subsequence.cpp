class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=0;i--) {
            for(int prevIdx=i;prevIdx>=0;prevIdx--) {
                int len = dp[i+1][prevIdx];
                if(prevIdx == 0 || nums[i] > nums[prevIdx-1]) {
                    len = max(len, 1 + dp[i+1][i+1]);
                }
                dp[i][prevIdx] = len;
            }
        }

        return dp[0][0];
    }
};