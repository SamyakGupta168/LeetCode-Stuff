class Solution {
    int dp[1001][1501][2];
    int f(int idx, int bu, int bought, vector<vector<int>>&items, vector<int>&cnt) {
        if(idx < 0 || bu <= 0) return 0;
        if(dp[idx][bu][bought] != -1) return dp[idx][bu][bought];

        int notTake = f(idx-1, bu, 0, items, cnt);

        int take = 0;
        int price = items[idx][1];
        if(bu >= price) {
            if(!bought) {
                take = cnt[idx] + f(idx, bu-price, 1, items, cnt);
            } else {
                take = 1 + f(idx, bu-price, 1, items, cnt);
            }
        }
        
        return dp[idx][bu][bought] = max(take, notTake);
    }


public:
    int maximumSaleItems(vector<vector<int>>& items, int bu) {
        int n = items.size();
        vector<int> cnt(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(items[j][0] % items[i][0] == 0) cnt[i]++;
            }
        }

        memset(dp, -1, sizeof(dp));
        return f(n-1, bu, 0, items, cnt);
    }
};