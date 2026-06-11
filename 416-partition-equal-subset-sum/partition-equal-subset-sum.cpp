class Solution {
public:
    int f(int i, int k, vector<int>&nums, vector<vector<int>>&dp) {
        int n = nums.size();
        if(k == 0) return 1;
        if(i == n) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int notTake = f(i+1, k, nums, dp);
        int take = 0;
        if(k >= nums[i]) take = f(i+1, k-nums[i], nums, dp);
        return dp[i][k] = (take | notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        int k = sum / 2;
        return f(0, k, nums, dp);
    }
};