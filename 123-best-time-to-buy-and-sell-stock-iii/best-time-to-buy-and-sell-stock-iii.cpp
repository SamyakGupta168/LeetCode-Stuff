class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cap=1;cap<=2;cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[i] + next[0][cap], next[1][cap]);
                    } else {
                        profit=  max(prices[i] + next[1][cap-1], next[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
                next = curr;
            }
        }

        return next[1][2];
    }
};