class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> minEffort(n, vector<int>(n, INT_MAX));
        minEffort[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == n-1) return effort;

            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int currEffort = max(effort, grid[nr][nc]);
                    if(currEffort < minEffort[nr][nc]) {
                        minEffort[nr][nc] = currEffort;
                        pq.push({minEffort[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};