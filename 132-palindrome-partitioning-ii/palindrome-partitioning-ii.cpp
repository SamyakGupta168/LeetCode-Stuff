class Solution {
public:

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, 0));

        for(int i=0;i<n;i++) isPal[i][i] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                if(j-i != 1) isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
                else isPal[i][j] = (s[i] == s[j]);
            }
        }

        vector<int> dp(n+1, 0);
        
        for(int i=n-1;i>=0;i--) {
            string temp = "";
            dp[i] = 1e9;
            for(int j=i;j<n;j++) {
                temp += s[j];
                if(isPal[i][j]) dp[i] = min(dp[i], 1 + dp[j+1]);
            }
        }

        return dp[0] - 1;
    }
};