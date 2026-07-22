class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int r=0;r<n;r++) {
            for(int c=0;c<m;c++) {
                int nc = (c + k) % m;
                int nr = r;
                if(c + k > m-1) {
                    nr = (r + (k + c) / m) % n;
                }
                ans[nr][nc] = grid[r][c];
            }
        }

        return ans;
    }
};