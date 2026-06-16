class Solution {
public:
    using ll = long long;

    ll f(int i, int k, vector<int>&nums, vector<vector<ll>>&dp) {
        if(i == 0) {
            if(k == 0) {
                if(nums[0] == 0) return 2;
                return 1;
            } else if(k == nums[0]) return 1;
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];

        ll notTake = f(i-1, k, nums, dp);
        ll take = 0;
        if(k >= nums[i]) take = f(i-1, k - nums[i], nums, dp);
        return dp[i][k] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(tar) > sum) return 0;
        vector<vector<ll>> dp(n, vector<ll>(sum+1, -1));
        int k = (sum - tar);
        if(k < 0 || k%2 == 1) return 0;
        return (int)f(n-1, k/2, nums, dp);
    }
};