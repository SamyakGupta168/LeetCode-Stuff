class Solution {
public:
    // 0 to n-2
    int f1(int idx, vector<int>&dp1, vector<int>&nums) {
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        if(dp1[idx] != -1) return dp1[idx];
        int sum1 = nums[idx] + f1(idx-2, dp1, nums);
        int sum2 = f1(idx-1, dp1, nums);
        return dp1[idx] = max(sum1, sum2);
    }

    // 1 to n-1
    int f2(int idx, vector<int>&dp2, vector<int>&nums) {
        if(idx < 1) return 0;
        if(idx == 1) return nums[1];
        if(dp2[idx] != -1) return dp2[idx];
        int sum1 = nums[idx] + f2(idx-2, dp2, nums);
        int sum2 = f2(idx-1, dp2, nums);
        return dp2[idx] = max(sum1, sum2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1), dp2(n, -1);
        return max(f1(n-2, dp1, nums), f2(n-1, dp2, nums));
    }
};