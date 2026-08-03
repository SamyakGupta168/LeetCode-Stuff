class Solution {
public:
    string stoneGameIII(vector<int>& val) {
        int n = val.size();
        vector<vector<int>> dp(2, vector<int>(n+2, 0));
        for(int i=n-1;i>=0;i--) {
            dp[0][i] = val[i] - dp[1][i+1];
            if(i+1 < n) dp[0][i] = max(dp[0][i], val[i] + val[i+1] - dp[1][i+2]);
            if(i+2 < n) dp[0][i] = max(dp[0][i], val[i] + val[i+1] + val[i+2] - dp[1][i+3]);

            dp[1][i] = val[i] - dp[0][i+1];
            if(i+1 < n) dp[1][i] = max(dp[1][i], val[i] + val[i+1] - dp[0][i+2]);
            if(i+2 < n) dp[1][i] = max(dp[1][i], val[i] + val[i+1] + val[i+2] - dp[0][i+3]);
        }

        if(dp[0][0] > 0) return "Alice";
        else if(dp[0][0] < 0) return "Bob";
        return "Tie";
    }
};