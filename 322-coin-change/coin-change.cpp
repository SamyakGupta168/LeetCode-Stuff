class Solution {
public:

    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int> dp(amt+1, 1e9);
        dp[0] = 0;

        for(int i=n-1;i>=0;i--) {
            for(int j=1;j<=amt;j++) {
                int take = INT_MAX;
                if(j >= coins[i]) dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }

        return (dp[amt] != 1e9 ? dp[amt] : -1);
    }
};