class Solution {
public:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    int f(int i, int j, string &s, vector<vector<int>>&dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        string temp = "";
        int mini = INT_MAX;
        for(int k=i;k<=j;k++) {
            temp += s[k];
            if(isPalindrome(temp)) mini = min(mini, 1 + f(k+1, j, s, dp));
        }
        return dp[i][j] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, s, dp) - 1;
    }
};