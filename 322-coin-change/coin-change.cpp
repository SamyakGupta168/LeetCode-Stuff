class Solution {
public:

    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int> prev(amt+1, 1e9), curr(amt+1, 1e9);
        
        for(int i=0;i<=amt;i++) {
            if(i % coins[0] == 0) prev[i] = i/coins[0];
        }

        for(int i=1;i<n;i++) {
            for(int j=0;j<=amt;j++) {
                int notTake = 0 + prev[j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        if(prev[amt] != 1e9) return prev[amt];
        return -1;
    }
};