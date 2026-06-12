class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(396, 0);

        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=365;j++) {
                if(j < days[i]) dp[j] = 1e9;
                dp[j] = min(dp[j], costs[0] + dp[max(j, days[i])]);
                dp[j] = min(dp[j], costs[1] + dp[max(j, days[i]+6)]);
                dp[j] = min(dp[j], costs[2] + dp[max(j, days[i]+29)]);
            }
        }

        return dp[0];
    }
};