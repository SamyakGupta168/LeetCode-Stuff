class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        vector<vector<int>> ans;
        sort(it.begin(), it.end());
        int st = it[0][0], end = it[0][1];
        for(int i=1;i<it.size();i++) {
            if(it[i][0] <= end) {
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