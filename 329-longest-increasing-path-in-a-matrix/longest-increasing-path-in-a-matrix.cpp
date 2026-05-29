class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> indegree(n, vector<int>(m, 0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int k=0;k<4;k++) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if(ni>=0 && nj>=0 && nj<m && ni<n) {
                        if(mat[i][j] < mat[ni][nj]) indegree[ni][nj]++;
                    }
                }
            }
        }

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!indegree[i][j]) q.push({{i, j}, 1});
            }
        }

        int ans = 0;
        while(!q.empty()) {
            auto [r, c] = q.front().first;
            int level = q.front().second;
            q.pop();
            ans = max(ans, level);

            for(int k=0;k<4;k++) {
                int nr = r + dy[k], nc = c + dx[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    if(mat[r][c] < mat[nr][nc]) {
                        indegree[nr][nc]--;
                        if(!indegree[nr][nc]) q.push({{nr, nc}, level+1});
                    }
                }
            }
        }

        return ans;
    }
};