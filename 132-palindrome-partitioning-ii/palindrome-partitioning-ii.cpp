class Solution {
public:
    bool check(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--) {
            string temp = "";
            dp[i] = INT_MAX;
            for(int j=i;j<n;j++) {
                temp += s[j];
                if(check(temp)) dp[i] = min(dp[i], 1 + dp[j+1]);
            }
        }

        return dp[0] - 1;
    }
};