class Solution {
public:
    int f(int i, int tar, vector<int>&nums, map<int,map<int,int>> &dp) {
        if(i < 0) {
            return tar == 0;
        }
        if(dp[i].count(tar)) return dp[i][tar];
        int ways = f(i-1, tar - nums[i], nums, dp);
        ways += f(i-1, tar + nums[i], nums, dp);
        return dp[i][tar] = ways;
    }

    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        map<int,map<int,int>> dp;
        return f(n-1, tar, nums, dp);
    }
};