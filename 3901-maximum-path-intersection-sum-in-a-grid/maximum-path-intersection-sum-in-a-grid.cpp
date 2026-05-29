class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = grid[0][0] + grid[0][1];

        for(int i=0;i<n;i++) {
            int dans = grid[i][0] + grid[i][1];

            if(i == 0 || i == n-1) {
                // Subarray of minimum size 2 will be taken
                int curr = dans;
                for(int j=2;j<m;j++) {
                    curr = max(curr + grid[i][j], grid[i][j-1] + grid[i][j]);
                    dans = max(dans, curr);
                }
            } else {
                int curr = max(0, grid[i][0]);
                for(int j=1;j<m;j++) {
                    curr += grid[i][j];
                    dans = max(dans, curr);
                    if(j != m-2) curr = max(0, curr);
                }
            }
            ans = max(ans, dans);
        }

        vector<vector<int>> dum(m, vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dum[i][j] = grid[j][i];
            }
        }

        for(int i=0;i<m;i++) {
            int dans = dum[i][0] + dum[i][1];

            if(i == 0 || i == m-1) {
                // Subarray of minimum size 2 will be taken
                int curr = dans;
                for(int j=2;j<n;j++) {
                    curr = max(curr + dum[i][j], dum[i][j-1] + dum[i][j]);
                    dans = max(dans, curr);
                }
            } else {
                int curr = max(0, dum[i][0]);
                for(int j=1;j<n;j++) {
                    curr += dum[i][j];
                    dans = max(dans, curr);
                    if(j != n-2) curr = max(0, curr);
                }
            }
            ans = max(ans, dans);
        }

        return ans;
    }
};