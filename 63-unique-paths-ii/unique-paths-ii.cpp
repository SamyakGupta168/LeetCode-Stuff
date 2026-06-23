class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> prev(m, 0), curr(m, 0);
        prev[0] = 1;
        curr[0] = 1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 && j == 0) continue;
                curr[j] = 0;
                if(i-1 >= 0 && grid[i-1][j] == 0) curr[j] += prev[j];
                if(j-1 >= 0 && grid[i][j-1] == 0) curr[j] += curr[j-1];
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
};