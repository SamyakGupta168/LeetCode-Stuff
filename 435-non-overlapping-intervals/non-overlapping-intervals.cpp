class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& it) {
        int n = it.size();
        sort(it.begin(), it.end(), [&] (auto &x1, auto &x2) -> bool {
            return x1[1] < x2[1];
        });

        int cnt = 1, ft = it[0][1];
        for(int i=1;i<n;i++) {
            if(ft <= it[i][0]) {
                cnt++;
                ft = it[i][1];
            }
        }

        return n - cnt;
    }
};