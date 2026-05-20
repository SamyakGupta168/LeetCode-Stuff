class Solution {
public:

    int uniquePaths(int n, int m) {
        vector<int> dp(m, -1);
        for(int i=0;i<n;i++) {
            vector<int> temp(m, -1);
            for(int j=0;j<m;j++) {
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }
                temp[j] = 0;
                if(j-1 >= 0) temp[j] += temp[j-1];
                if(i-1 >= 0) temp[j] += dp[j]; 
            }
            dp = temp;
        }

        return dp[m-1];
    }
};