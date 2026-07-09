class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&pairs) {
        int n = pairs.size();
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(j == 0) {
            int notTake = f(i+1, j, dp, pairs);
            int take = 1 + f(i+1, i+1, dp, pairs);
            return dp[i][j] = max(take, notTake);
        }

        int notTake = f(i+1, j, dp, pairs);
        int take = 0;
        if(pairs[j-1][1] < pairs[i][0]) {
            take = 1 + f(i+1, i+1, dp, pairs);
        }
        return dp[i][j] = max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, 0, dp, pairs);
    }
};