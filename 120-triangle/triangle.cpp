class Solution {
public:

    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        vector<int> dp(n, -1);
        for(int i=0;i<n;i++) {
            dp[i] = tr[n-1][i];
        }

        for(int i=n-2;i>=0;i--) {
            vector<int> temp(i+1, 0);
            for(int j=0;j<=i;j++) {
                temp[j] = tr[i][j] + min(dp[j], dp[j+1]);
            }
            for(int j=0;j<=i;j++) {
                dp[j] = temp[j];
            }
        }

        return dp[0];
    }
};