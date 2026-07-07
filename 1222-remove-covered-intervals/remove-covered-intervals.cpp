class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& it) {
        int n = it.size();
        int rem = 0;
        sort(it.begin(), it.end());
        int last = 0, maxi = it[0][1];
        for(int i=1;i<n;i++) {
            if(it[i][0] == it[last][0]) {
                rem++;
                maxi = it[i][1];
                last = i;
                continue;
            }
            if(it[i][1] <= maxi) {
                rem++;
                continue;
            }
            maxi = it[i][1];
            last = i;
        }
        
        return n - rem;
    }
};