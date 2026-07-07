class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& it) {
        int n = it.size();
        vector<int> sink(n, 0);
        for(int i=0;i<n;i++) {
            int st = it[i][0], end = it[i][1];
            for(int j=0;j<n;j++) {
                if(j == i) continue;
                if(st <= it[j][0] && it[j][1] <= end) sink[j] = 1;
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++) if(!sink[i]) cnt++;
        return cnt;
    }
};