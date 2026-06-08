class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);
        int maxIdx = -1, len = 0;
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(nums[i] % nums[prev] == 0) {
                    if(1 + dp[prev] > dp[i]) {
                        dp[i] = 1 + dp[prev];
                        prevIdx[i] = prev;
                    }
                }
            }
            if(dp[i] > len) {
                len = dp[i];
                maxIdx = i;
            }
        }
        
        int idx = maxIdx;
        vector<int> res;
        while(idx != -1) {
            res.push_back(nums[idx]);
            idx = prevIdx[idx];
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};