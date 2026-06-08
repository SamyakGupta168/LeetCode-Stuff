class Solution {
public:
    int f(int idx, int prevIdx, vector<int>&nums, vector<vector<int>>&dp) {
        int n = nums.size();
        if(idx == n) return 0;
        if(dp[idx][prevIdx] != -1) return dp[idx][prevIdx];

        int len = 0 + f(idx+1, prevIdx, nums, dp); // Not take case
        if(prevIdx == 0 || nums[idx] > nums[prevIdx-1]) { // Take case
            len = max(len, 1 + f(idx+1, idx+1, nums, dp));
        }

        return dp[idx][prevIdx] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, 0, nums, dp);
    }
};