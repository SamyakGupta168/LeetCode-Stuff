class Solution {
public:
    int f(int i, int ub, vector<int>&days, vector<int>&costs, vector<vector<int>>&dp) {
        int n = days.size();
        if(i == n) return 0;
        if(dp[i][ub] != -1) return dp[i][ub];
        
        int notBuy = 1e9;
        if(ub >= days[i]) {
            notBuy = 0 + f(i+1, ub, days, costs, dp);
        }

        int buy = costs[0] + f(i+1, max(ub, days[i]), days, costs, dp);
        buy = min(buy, costs[1] + f(i+1, max(ub, days[i]+6), days, costs, dp));
        buy = min(buy, costs[2] + f(i+1, max(ub, days[i]+29), days, costs, dp));

        return dp[i][ub] = min(buy, notBuy);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(396, -1));
        return f(0, 0, days, costs, dp);
    }
};