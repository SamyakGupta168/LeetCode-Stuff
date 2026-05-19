class Solution {
public:
    int f(int idx, vector<int>&nums, vector<int>&dp) {
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        if(dp[idx] != -1) return dp[idx];

        int sum1 = nums[idx] + f(idx-2, nums, dp);
        int sum2 = f(idx-1, nums, dp);
        return dp[idx] = max(sum1, sum2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};