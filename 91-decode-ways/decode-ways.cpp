class Solution {
public:
    int f(int i, string &s, vector<int>&dp) {
        int n = s.size();
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];

        int ways = 0;
        int x1 = s[i] - '0';
        if(x1 == 0) return 0;
        ways += 1*f(i+1, s, dp);

        if(i+1 < n) {
            int x2 = s[i+1] - '0';
            int num = x1*10 + x2;
            if(num <= 26) {
                ways += 1*f(i+2, s, dp);
            }
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        vector<int> dp((int)s.size(), -1);
        return f(0, s, dp);
    }
};