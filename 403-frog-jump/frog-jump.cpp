class Solution {
public:

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> idx;
        for(int i=0;i<stones.size();i++) {
            idx[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=1;i<n;i++) dp[n-1][i] = 1;

        for(int i=n-2;i>=0;i--) {
            for(int k=1;k<n;k++) {
                if(i == 0 && k>1) break;
                int isPoss = 0;
                if(i != 0 && idx.count(stones[i]+k-1) && idx[stones[i]+k-1] > i) isPoss |= dp[idx[stones[i]+k-1]][k-1];
                if(idx.count(stones[i]+k) && idx[stones[i]+k] > i) isPoss |= dp[idx[stones[i]+k]][k];
                if(k < n-1 && i != 0 && idx.count(stones[i]+k+1) && idx[stones[i]+k+1] > i) isPoss |= dp[idx[stones[i]+k+1]][k+1];
                dp[i][k] = isPoss;
            }
        }

        return dp[0][1];
    }
};