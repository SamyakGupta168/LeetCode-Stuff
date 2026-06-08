class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    } else if(1 + dp[j] == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int lis = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(lis == dp[i]) ans += cnt[i];
        }

        return ans;
    }
};