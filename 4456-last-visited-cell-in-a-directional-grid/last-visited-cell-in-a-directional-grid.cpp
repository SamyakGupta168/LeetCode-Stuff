class Solution {
public:
    
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int i = 0, j = 0;
        int r = -1, c = -1;
        while(i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]) {
            vis[i][j] = 1;
            r = i, c = j;
            // cout<<r<<" "<<c<<'\n';
            if(grid[r][c] == 'L') j--;
            else if(grid[r][c] == 'R') j++;
            else if(grid[r][c] == 'U') i--;
            else if(grid[r][c] == 'D') i++;
        } 

        return {r, c};
    }
};