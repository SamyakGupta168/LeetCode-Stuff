class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size(), m = grid[0].size();
        int idx = 1;
        for(int i=0;i<k/2;i++) {
            for(int j=0;j<k;j++) {
                swap(grid[x+i][y+j], grid[x+k-i-1][y+j]);
            }
        }

        return grid;
    }
};