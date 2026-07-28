class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int i=m-1;i>=0;i--) {
            for(int j=i;j<m;j++) {
                if(j - i <= 1) continue;
                dp[i][j] = 1e9;
                for(int k=i+1;k<j;k++) {
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][m-1];
    }
};