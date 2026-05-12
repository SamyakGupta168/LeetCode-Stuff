class Solution {
public:
    int INF = 1e8;

    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(auto &v : edges) {
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];
        }
        
        for(int i=0;i<n;i++) dist[i][i] = 0;
        
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dist[i][k] != INF && dist[k][j] != INF) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int cnt = n, city = -1;
        for(int i=0;i<n;i++) {
            int cities = 0;
            for(int j=0;j<n;j++) {
                if(i != j && dist[i][j] <= th) cities++;
            }
            if(cities <= cnt) {
                city = i;
                cnt = cities;
            }
        }
        
        return city;
    }
};