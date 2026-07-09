class Solution {
public:
    using ll = long long;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<ll, map<ll,ll>> dp;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ll diff = (ll)nums[j] - nums[i];
                int cnt = dp[i][diff];
                ans += cnt;
                dp[j][diff] += cnt+1;
            }
        }

        return ans;
    }
};