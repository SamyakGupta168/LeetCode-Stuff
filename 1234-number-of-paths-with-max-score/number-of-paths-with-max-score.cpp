class Solution {
public:
    int mod = 1e9 + 7;
    bool isValid(int i, int n, int j, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector<int> next(m, -1), curr(m, -1);
        vector<int> currWays(m, 0), nextWays(m, 0);
        next[m-1] = 0;
        nextWays[m-1] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i == n-1 && j == m-1) {
                    curr[j] = 0;
                    currWays[j] = 1;
                    continue;
                }
                if(board[i][j] == 'X') continue;
                int maxVal = -1;
                if(isValid(i, n, j+1, m)) maxVal = max(maxVal, curr[j+1]);
                if(isValid(i+1, n, j, m)) maxVal = max(maxVal, next[j]);
                if(isValid(i+1, n, j+1, m)) maxVal = max(maxVal, next[j+1]);
                if(maxVal != -1) {
                    if(i == 0 && j == 0) curr[j] = maxVal;
                    else curr[j] = (board[i][j] - '0') + maxVal;
                    if(isValid(i, n, j+1, m) && curr[j+1] == maxVal) currWays[j] += currWays[j+1];
                    currWays[j] %= mod;
                    if(isValid(i+1, n, j, m) && next[j] == maxVal) currWays[j] += nextWays[j];
                    currWays[j] %= mod;
                    if(isValid(i+1, n, j+1, m) && next[j+1] == maxVal) currWays[j] += nextWays[j+1];
                    currWays[j] %= mod;
                }
            }
            next = curr;
            nextWays = currWays;
            fill(curr.begin(), curr.end(), -1);
            fill(currWays.begin(), currWays.end(), 0);
        }

        if(next[0] == -1) return {0, 0};
        return {next[0], nextWays[0]};
    }
};