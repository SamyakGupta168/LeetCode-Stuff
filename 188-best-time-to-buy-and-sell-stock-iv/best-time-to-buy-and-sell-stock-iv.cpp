class Solution {
public:
    int f(int i, int buy, int cap, vector<vector<vector<int>>>&dp, vector<int>&prices) {
        int n = prices.size();
        if(i == n) return 0;
        if(cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int maxi = 0;
        if(buy) {
            maxi = max(maxi, -prices[i] + f(i+1, 0, cap, dp, prices));
            maxi = max(maxi, f(i+1, 1, cap ,dp, prices));
        } else {
            maxi = max(maxi, prices[i] + f(i+1, 1, cap-1, dp, prices));
            maxi = max(maxi, f(i+1, 0, cap, dp, prices));
        }

        return dp[i][buy][cap] = maxi;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(k+1, -1)));
        return f(0, 1, k, dp, prices);
    }
};