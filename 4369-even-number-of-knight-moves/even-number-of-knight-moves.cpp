class Solution {
public:
    bool canReach(vector<int>& st, vector<int>& tar) {
        vector<vector<vector<int>>> vis(8, vector<vector<int>>(8, vector<int>(2, 0)));
        vis[st[0]][st[1]][0] = 1;
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {st[0], st[1]}});
        while(!q.empty()) {
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if(r - 1 >= 0 && c - 2 >= 0 && !vis[r-1][c-2][(steps+1)%2]) {
                vis[r-1][c-2][(steps+1)%2] = 1;
                q.push({steps+1, {r-1, c-2}});
            }
            if(r - 1 >= 0 && c + 2 < 8 && !vis[r-1][c+2][(steps+1)%2]) {
                vis[r-1][c+2][(steps+1)%2] = 1;
                q.push({steps+1, {r-1, c+2}});
            }
            if(r + 1 < 8 && c - 2 >= 0 && !vis[r+1][c-2][(steps+1)%2]) {
                vis[r+1][c-2][(steps+1)%2] = 1;
                q.push({steps+1, {r+1, c-2}});
            }
            if(r + 1 < 8 && c + 2 < 8 && !vis[r+1][c+2][(steps+1)%2]) {
                vis[r+1][c+2][(steps+1)%2] = 1;
                q.push({steps+1, {r+1, c+2}});
            }
            if(r - 2 >= 0 && c - 1 >= 0 && !vis[r-2][c-1][(steps+1)%2]) {
                vis[r-2][c-1][(steps+1)%2] = 1;
                q.push({steps+1, {r-2, c-1}});
            }
            if(r + 2 < 8 && c - 1 >= 0 && !vis[r+2][c-1][(steps+1)%2]) {
                vis[r+2][c-1][(steps+1)%2] = 1;
                q.push({steps+1, {r+2, c-1}});
            }
            if(r - 2 >= 0 && c + 1 < 8 && !vis[r-2][c+1][(steps+1)%2]) {
                vis[r-2][c+1][(steps+1)%2] = 1;
                q.push({steps+1, {r-2, c+1}});
            }
            if(r + 2 < 8 && c + 1 < 8 && !vis[r+2][c+1][(steps+1)%2]) {
                vis[r+2][c+1][(steps+1)%2] = 1;
                q.push({steps+1, {r+2, c+1}});
            }
        }

        return vis[tar[0]][tar[1]][0];
    }
};