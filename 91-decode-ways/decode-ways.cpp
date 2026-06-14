class Solution {
public:

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int i=n-1;i>=0;i--) {
            int ways = 0;
            int x1 = s[i] - '0';
            if(x1 == 0) {
                dp[i] = 0;
                continue;
            }
            ways += 1*dp[i+1];

            if(i+1 < n) {
                int x2 = s[i+1] - '0';
                int num = x1*10 + x2;
                if(num <= 26) {
                    ways += 1*dp[i+2];
                }
            }

            dp[i] = ways;
        }

        return dp[0];
    }
};