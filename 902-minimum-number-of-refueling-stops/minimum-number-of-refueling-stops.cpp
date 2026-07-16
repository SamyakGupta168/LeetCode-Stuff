class Solution {
public:
    using ll = long long;
    int minRefuelStops(int tar, int start, vector<vector<int>>& st) {
        st.insert(st.begin(), {0, start});
        int n = st.size();
        vector<vector<ll>> dp(n, vector<ll>(n, -1));
        dp[0][0] = start;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(j>0 && dp[i-1][j-1] != -1) {
                    if(dp[i-1][j-1] + st[i-1][1] >= st[i][0] - st[i-1][0]) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + st[i-1][1] - st[i][0] + st[i-1][0]);
                    }
                }

                if(dp[i-1][j] != -1 && dp[i-1][j] >= st[i][0] - st[i-1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] - st[i][0] + st[i-1][0]);
                }
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<n;j++) {
            if(dp[n-1][j] != -1) {
                if(st[n-1][0] + dp[n-1][j] >= tar) ans = min(ans, j);
                if(st[n-1][0] + dp[n-1][j] + st[n-1][1] >= tar) ans = min(ans, j+1);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};