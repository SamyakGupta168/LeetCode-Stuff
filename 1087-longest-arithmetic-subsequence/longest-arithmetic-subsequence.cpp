class Solution {
public:
    int f(int prev, int diff, vector<vector<int>>&dp, vector<int>&nums) {
        if(dp[prev][diff + 500] != -1) return dp[prev][diff+500];
        int maxLen = 0;
        for(int i=prev+1;i<nums.size();i++) {
            if(nums[i] - nums[prev] == diff) {
                maxLen = max(maxLen, 1 + f(i, diff, dp, nums));
            }
        }
        return dp[prev][diff+500] = maxLen;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, -1));
        int maxi = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                maxi = max(maxi, 2 + f(j, nums[j] - nums[i], dp, nums));
            }
        }

        return maxi;
    }
};