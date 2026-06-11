class Solution {
public:
    int f(int i, int flag, vector<int>&nums, vector<vector<int>>&dp) {
        int n = nums.size();
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int notTake = f(i+1, 1, nums, dp);
        int take = 0;
        if(flag) take = nums[i] + f(i+1, 0, nums, dp);
        return dp[i][flag] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, nums, dp);
    }
};