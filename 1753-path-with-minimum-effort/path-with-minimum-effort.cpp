class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1) return dis;
            
            for(int i=0;i<4;i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    if(max(dis, diff) < dist[nr][nc]) {
                        dist[nr][nc] = max(dis, diff);
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};