class Solution {
public:

    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        for(int j1=0;j1<m;j1++) {
            for(int j2=0;j2<m;j2++) {
                if(j1 == j2) dp[n-1][j1][j2] = a[n-1][j1];
                else dp[n-1][j1][j2] = a[n-1][j1] + a[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--) {
            for(int j1=0;j1<m;j1++) {
                for(int j2=0;j2<m;j2++) {
                    int maxi = 0;
                    for(int dj1=-1;dj1<=1;dj1++) {
                        for(int dj2=-1;dj2<=1;dj2++) {
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) {
                                if(j1==j2) maxi = max(maxi, a[i][j1] + dp[i+1][j1+dj1][j2+dj2]);
                                else maxi = max(maxi, a[i][j1] + a[i][j2] + dp[i+1][j1+dj1][j2+dj2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};