class Solution {
public:

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(n, -1), curr(n, -1);
        for(int i=0;i<n;i++) {
            prev[i] = 1;
        }

        int ans = 0;
        for(int j=m-2;j>=0;j--) {
            for(int i=0;i<n;i++) {
                int cnt = 1;
                if(i-1>=0 && j+1<m && grid[i][j] < grid[i-1][j+1]) cnt = max(cnt, 1 + prev[i-1]);
                if(j+1<m && grid[i][j] < grid[i][j+1]) cnt = max(cnt, 1 + prev[i]);
                if(i+1<n && j+1<m && grid[i][j] < grid[i+1][j+1]) cnt = max(cnt, 1 + prev[i+1]);
                curr[i] = cnt;
                if(j == 0) ans = max(ans, curr[i]);
            }
            prev = curr;
        }

        return ans - 1;
    }
};