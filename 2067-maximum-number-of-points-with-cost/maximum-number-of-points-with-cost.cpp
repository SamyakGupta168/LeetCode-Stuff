class Solution {
public:
    using ll = long long;
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        for(int j=0;j<m;j++) {
            dp[0][j] = points[0][j];
        }

        vector<ll> left(m, dp[0][0]), right(m, dp[0][m-1] - m + 1);
        for(int j=1;j<m;j++) left[j] = max(left[j-1], dp[0][j] + j);
        for(int j=m-2;j>=0;j--) right[j] = max(right[j+1], dp[0][j] - j);

        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j] = points[i][j] + max(left[j] - j, right[j] + j);
            }

            left[0] = dp[i][0];
            right[m-1] = dp[i][m-1] - m + 1;
            for(int j=1;j<m;j++) {
                left[j] = 0;
                left[j] = max(left[j-1], dp[i][j] + j);
            }
            for(int j=m-2;j>=0;j--) {
                right[j] = 0;
                right[j] = max(right[j+1], dp[i][j] - j);
            }
        }

        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};