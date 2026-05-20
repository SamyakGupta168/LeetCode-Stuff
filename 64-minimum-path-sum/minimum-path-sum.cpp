class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, -1);
        for(int i=0;i<n;i++) {
            vector<int> temp(m, 1e8);
            for(int j=0;j<m;j++) {
                if(i == 0 && j == 0) {
                    temp[j] = grid[0][0];
                    continue;
                }
                if(j-1 >= 0) temp[j] = min(temp[j], temp[j-1]);
                if(i-1 >= 0) temp[j] = min(temp[j], dp[j]);
                temp[j] += grid[i][j];
            }
            dp = temp;
        }

        return dp[m-1];
    }
};