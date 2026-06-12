class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n+1, vector<int>(396, 0));

        for(int i=n-1;i>=0;i--) {
            for(int j=365;j>=0;j--) {
                int notBuy = 1e9;
                if(j >= days[i]) notBuy = dp[i+1][j];
                int buy = costs[0] + dp[i+1][max(j, days[i])];
                buy = min(buy, costs[1] + dp[i+1][max(j, days[i]+6)]);
                buy = min(buy, costs[2] + dp[i+1][max(j, days[i]+29)]);
                dp[i][j] = min(buy, notBuy);
            }
        }

        return dp[0][0];
    }
};