class Solution {
public:
    int f(int idx, int buy, int flag, vector<int>&prices, vector<vector<vector<int>>>&dp) {
        int n = prices.size();
        if(idx == n) return 0;
        if(dp[idx][buy][flag] != -1) return dp[idx][buy][flag];
        
        int profit = 0;
        if(buy) {
            if(flag) {
                profit = max(-prices[idx] + f(idx+1, 0, 1, prices, dp), f(idx+1, 1, 1, prices, dp));
            } else {
                profit = f(idx+1, 1, 1, prices, dp);
            }
        } else {
            if(flag) profit = max(prices[idx] + f(idx+1, 1, 0, prices, dp), f(idx+1, 0, 1, prices, dp));
        }
        return dp[idx][buy][flag] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(2, -1)));
        return f(0, 1, 1, prices, dp);
    }
};