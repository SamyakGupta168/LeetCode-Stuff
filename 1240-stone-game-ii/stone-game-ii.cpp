class Solution {
public:
    int dp[2][101][101];

    int f(int person, int i, int m, vector<int>&piles, int dp[][101][101]) {
        int n = piles.size();
        if(i >= n) return 0;
        if(dp[person][i][m] != -1) return dp[person][i][m];
        int result = (person == 1 ? INT_MIN : INT_MAX);
        int stones = 0;

        for(int x=1;x<=min(2*m, n-i);x++) {
            int idx = i + x - 1;
            stones += piles[idx];
            if(person == 1) {
                result = max(result, stones + f(0, idx+1, max(x, m), piles, dp));
            } else {
                result = min(result, f(1, idx+1, max(x, m), piles, dp));
            }
        }

        return dp[person][i][m] = result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return f(1, 0, 1, piles, dp);
    }
};