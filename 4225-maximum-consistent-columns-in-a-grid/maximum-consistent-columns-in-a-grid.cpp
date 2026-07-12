class Solution {
public:
    bool check(int i, int j, vector<vector<int>>&grid, int limit) {
        int n = grid.size();
        for(int k=0;k<n;k++) {
            if(abs(grid[k][i] - grid[k][j]) > limit) return false;
        }
        return true;
    }
    
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int> dp(m+1, 0);
        for(int i=1;i<=m;i++) {
            dp[i] = 1;
            for(int j=1;j<i;j++) {
                if(check(i-1, j-1, grid, limit)) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};