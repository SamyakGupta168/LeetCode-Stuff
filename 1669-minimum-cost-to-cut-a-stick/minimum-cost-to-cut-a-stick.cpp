class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        for(int i=c;i>=1;i--) {
            for(int j=i;j<=c;j++) {
                dp[i][j] = 1e9;
                for(int k=i;k<=j;k++) {
                    dp[i][j] = min(dp[i][j], cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }

        return dp[1][c];
    }
};