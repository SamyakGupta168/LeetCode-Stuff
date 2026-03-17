class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> temp(n, vector<int>(m));
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==1) temp[i][j] = 1 + ((i+1<n) ? temp[i+1][j] : 0);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            sort(temp[i].begin(), temp[i].end());
            for(int j=0;j<m;j++) {
                ans = max(ans, temp[i][j]*(m-j));
            }
        }

        return ans;
    }
};