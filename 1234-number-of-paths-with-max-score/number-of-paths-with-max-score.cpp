class Solution {
public:
    int mod = 1e9 + 7;
    bool isValid(int i, int n, int j, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<int>> ways(n, vector<int>(m, 0));
        dp[n-1][m-1] = 0;
        ways[n-1][m-1] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i == n-1 && j == m-1) continue;
                if(board[i][j] == 'X') continue;
                int maxVal = -1;
                if(isValid(i, n, j+1, m)) maxVal = max(maxVal, dp[i][j+1]);
                if(isValid(i+1, n, j, m)) maxVal = max(maxVal, dp[i+1][j]);
                if(isValid(i+1, n, j+1, m)) maxVal = max(maxVal, dp[i+1][j+1]);
                if(maxVal != -1) {
                    if(i == 0 && j == 0) dp[i][j] = maxVal;
                    else dp[i][j] = (board[i][j] - '0') + maxVal;
                    if(isValid(i, n, j+1, m) && dp[i][j+1] == maxVal) ways[i][j] += ways[i][j+1];
                    ways[i][j] %= mod;
                    if(isValid(i+1, n, j, m) && dp[i+1][j] == maxVal) ways[i][j] += ways[i+1][j];
                    ways[i][j] %= mod;
                    if(isValid(i+1, n, j+1, m) && dp[i+1][j+1] == maxVal) ways[i][j] += ways[i+1][j+1];
                    ways[i][j] %= mod;
                }
            }
        }

        if(dp[0][0] == -1) return {0, 0};
        return {dp[0][0], ways[0][0]};
    }
};