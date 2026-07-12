class Solution {
public:
    bool check(int i, int j, vector<vector<int>>&grid, int limit) {
        int n = grid.size();
        for(int k=0;k<n;k++) {
            if(abs(grid[k][i] - grid[k][j]) > limit) return false;
        }
        return true;
    }

    int f(int i, vector<vector<int>>&grid, int limit, vector<int>&dp) {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        int maxi = 1;
        for(int j=0;j<i;j++) {
            if(check(i, j, grid, limit)) {
                maxi = max(maxi, 1 + f(j, grid, limit, dp));
            }
        }

        return dp[i] = maxi;
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int> dp(m, -1);
        for(int i=0;i<m;i++) {
            ans = max(ans, f(i, grid, limit, dp));
        }

        return ans;
    }
};