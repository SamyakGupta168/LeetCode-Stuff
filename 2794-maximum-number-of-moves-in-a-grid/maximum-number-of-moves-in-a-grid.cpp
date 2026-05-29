class Solution {
public:

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<n;i++) {
            dp[i][m-1] = 1;
        }

        int ans = 0;
        for(int j=m-2;j>=0;j--) {
            for(int i=0;i<n;i++) {
                int cnt = 1;
                if(i-1>=0 && j+1<m && grid[i][j] < grid[i-1][j+1]) cnt = max(cnt, 1 + dp[i-1][j+1]);
                if(j+1<m && grid[i][j] < grid[i][j+1]) cnt = max(cnt, 1 + dp[i][j+1]);
                if(i+1<n && j+1<m && grid[i][j] < grid[i+1][j+1]) cnt = max(cnt, 1 + dp[i+1][j+1]);
                dp[i][j] = cnt;
                if(j == 0) ans = max(ans, dp[i][0]);
            }
        }

        return ans - 1;
    }
};