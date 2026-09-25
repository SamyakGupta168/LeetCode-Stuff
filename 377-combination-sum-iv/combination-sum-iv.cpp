class Solution {
public:
    using ll = long long;

    int combinationSum4(vector<int>& nums, int tar) {
        vector<ll> dp(tar+1, 0);
        dp[0] = 1;
        for(int sum=1;sum<=tar;sum++) {
            for(auto x : nums) {
                if(x <= sum) {
                    dp[sum] += dp[sum - x];
                    if(dp[sum] > INT_MAX) dp[sum] = INT_MAX;
                }
            }
        }

        return (int)dp[tar];
    }
};