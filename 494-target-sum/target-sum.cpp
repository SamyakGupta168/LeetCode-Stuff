class Solution {
public:
    int f(int i, vector<int>&nums, int tar) {
        if(i < 0) {
            return tar == 0;
        }
        int ways = f(i-1, nums, tar - nums[i]);
        ways += f(i-1, nums, tar + nums[i]);
        return ways;
    }

    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        return f(n-1, nums, tar);
    }
};