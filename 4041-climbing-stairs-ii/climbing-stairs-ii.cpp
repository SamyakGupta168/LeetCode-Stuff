class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++) {
            dp[i] = costs[i-1];
            int ext = INT_MAX;
            if(i-1 >= 0) ext = min(ext, 1 + dp[i-1]);
            if(i-2 >= 0) ext = min(ext, 4 + dp[i-2]);
            if(i-3 >= 0) ext = min(ext, 9 + dp[i-3]);
            dp[i] += ext;
        }

        return dp[n];
    }
};