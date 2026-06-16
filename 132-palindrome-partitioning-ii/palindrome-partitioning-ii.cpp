class Solution {
public:

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n+1, vector<bool>(n+1, true));

        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                isPal[i][j] = false;
                isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
            }
        }

        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--) {
            dp[i] = 1e9;
            string temp;
            for(int j=i;j<n;j++) {
                temp += s[j];
                if(isPal[i][j]) dp[i] = min(dp[i], 1 + dp[j+1]);
            }
        }

        return dp[0] - 1;
    }
};