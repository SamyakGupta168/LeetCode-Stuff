class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void bfs(vector<vector<int>>&mat, vector<vector<int>>&vis, vector<vector<int>>&dist) {
        int n=mat.size(), m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    vis[i][j]=1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()) {
            auto [r, c] = q.front().first;
            int d = q.front().second;
            dist[r][c]=d;
            q.pop();
            for(int i=0;i<4;i++) {
                int nr = r + dy[i], nc = c + dx[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    if(!vis[nr][nc] && mat[nr][nc]==1) {
                        vis[nr][nc]=1;
                        q.push({{nr, nc}, d+1});
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m)), dist(n, vector<int>(m));
        bfs(mat, vis, dist);
        return dist;
    }
};