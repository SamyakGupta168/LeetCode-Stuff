class Solution {
public:
    double dp[25][25][101];
    int dx[8] = {1, 2, -1, -2, 1, -1, -2, 2};
    int dy[8] = {2, 1, -2, -1, -2, 2, 1, -1};

    double f(int i, int j, int k, int n) {
        if(k == 0) {
            if(i < 0 || j < 0 || i >= n || j >= n) return 0;
            return 1;
        }
        if(i < 0 || j < 0 || i >= n || j >= n) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        double ways = 0;
        for(int z=0;z<8;z++) {
            int ni = i + dx[z], nj = j + dy[z];
            ways += f(ni, nj, k-1, n);
        }
        return dp[i][j][k] = ways;
    }

    double knightProbability(int n, int k, int r, int c) {
        fill(&dp[0][0][0], &dp[0][0][0] + 25*25*101, -1.0);
        double valid = f(r, c, k, n);

        double tot = pow(8.0, k);
        return valid / tot;
    }
};