class Solution {
public:
    int f(int i, int j, int flag, vector<vector<vector<int>>>&dp, vector<int>&piles) {
        if(i > j) return 0;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        int maxi = 0;
        if(flag) {
            maxi = max(maxi, piles[i] + f(i+1, j, 0, dp, piles));
            maxi = max(maxi, piles[j] + f(i, j-1, 0, dp, piles));
        } else {
            maxi = max(maxi, -piles[i] + f(i+1, j, 1, dp, piles));
            maxi = max(maxi, -piles[j] + f(i, j-1, 1, dp, piles));
        }
        return dp[i][j][flag] = maxi;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int maxScore = f(0, n-1, 1, dp, piles);

        return (maxScore > 0);
    }
};