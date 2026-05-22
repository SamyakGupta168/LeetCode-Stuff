class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> dp(m, -1);
        for(int j=0;j<m;j++) {
            dp[j] = mat[0][j];
        }
        
        for(int i=1;i<n;i++) {
            vector<int> temp(m, 1e9);
            for(int j=0;j<m;j++) {
                temp[j] = min(temp[j], mat[i][j] + dp[j]);
                if(j-1 >= 0) temp[j] = min(temp[j], mat[i][j] + dp[j-1]);
                if(j+1 < m) temp[j] = min(temp[j], mat[i][j] + dp[j+1]);
            }
            dp = temp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};