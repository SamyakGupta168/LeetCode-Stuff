class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[1][0] > 1 && grid[0][1] > 1) return -1;

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int mt = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(mt != minTime[r][c]) continue;

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int diff = grid[nr][nc] - mt;
                int time = -1;
                if(diff <= 0) time = mt + 1;
                else if(diff & 1) time = grid[nr][nc];
                else time = grid[nr][nc] + 1;
                if(time < minTime[nr][nc]) {
                    minTime[nr][nc] = time;
                    pq.push({minTime[nr][nc], {nr, nc}});
                }
            }
        }

        return (minTime[n-1][m-1] != INT_MAX ? minTime[n-1][m-1] : -1); 
    }
};