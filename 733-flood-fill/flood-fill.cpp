class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int orgColor = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            image[r][c] = color;
            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    if(image[nr][nc] == orgColor && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }


        return image;
    }
};