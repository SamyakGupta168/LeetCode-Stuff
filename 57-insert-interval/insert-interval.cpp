class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& nit) {
        int n = it.size();
        int idx = -1;
        for(int i=0;i<n;i++) {
            if(it[i][0] >= nit[0]) {
                idx = i;
                break;
            }
        }
        
        if(idx == -1) it.push_back(nit);
        else it.insert(it.begin() + idx, nit);

        vector<vector<int>> ans;
        int st = it[0][0], end = it[0][1];
        for(int i=1;i<n+1;i++) {
            if(end >= it[i][0]) {
                end = max(end, it[i][1]);
            } else {
                ans.push_back({st, end});
                st = it[i][0], end = it[i][1];
            }
        }
        ans.push_back({st, end});

        return ans;
    }
};