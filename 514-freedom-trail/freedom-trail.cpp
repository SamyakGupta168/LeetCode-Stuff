class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = key.size(), m = ring.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<m;i++) {
            if(key[0] == ring[i]) dp[0][i] = min(i+1, m-i+1);
        }

        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(key[i] != ring[j]) continue;
                dp[i][j] = INT_MAX;
                for(int k=0;k<m;k++) {
                    if(dp[i-1][k] != -1) {
                        int d = min(abs(k - j), m - abs(k - j));
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + d + 1);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<m;j++) {
            if(dp[n-1][j] != -1) ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};