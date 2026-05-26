class Solution {
public:

    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amt+1, 0), curr(amt+1, 0);
        prev[0] = 1, curr[0] = 1;

        for(int i=0;i<=amt;i++) {
            if(i % coins[0] == 0) prev[i] = 1; 
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<=amt;j++) {
                int notTake = prev[j];
                int take = 0;
                if(coins[i] <= j) {
                    take = curr[j - coins[i]];
                }
                curr[j] = (long long)take + notTake;
            }
            prev = curr;
        }

        return prev[amt];
    }
};