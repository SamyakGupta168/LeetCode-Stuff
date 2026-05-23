class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;

        sum /= 2;

        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        for(int i=0;i<=sum;i++) {
            dp[0][i] = 0;
        }
        for(int i=0;i<n;i++) {
            dp[i][0] = 1;
        }
        if(nums[0] <= sum) dp[0][nums[0]] = 1;
        
        for(int i=1;i<n;i++) {
            for(int target=1;target<=sum;target++) {
                int notTake = dp[i-1][target];
                int take = 0;
                if(target >= nums[i]) {
                    take = dp[i-1][target-nums[i]];
                }
                dp[i][target] = (take|notTake);
            }
        }
        
        return dp[n-1][sum];
    }
};