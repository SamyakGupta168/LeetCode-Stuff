class Solution {
public:
    int f(int i, int k, vector<int>&stones, vector<vector<int>>&dp, map<int,int>&idx) {
        if(i == stones.size()-1) return 1;
        if(dp[i][k] != -1) return dp[i][k];

        int isPoss = 0;
        if(i != 0 && idx.count(stones[i]+k-1) && idx[stones[i]+k-1] > i) isPoss |= f(idx[stones[i]+k-1], k-1, stones, dp, idx);
        if(idx.count(stones[i]+k) && idx[stones[i]+k] > i) isPoss |= f(idx[stones[i]+k], k, stones, dp, idx);
        if(i != 0 && idx.count(stones[i]+k+1) && idx[stones[i]+k+1] > i) isPoss |= f(idx[stones[i]+k+1], k+1, stones, dp, idx);
        return dp[i][k] = isPoss;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int,int> idx;
        for(int i=0;i<stones.size();i++) {
            idx[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, 1, stones, dp, idx);
    }
};