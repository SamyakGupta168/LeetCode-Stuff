class Solution {
public:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    int f(int i, string &s, vector<int>&dp) {
        int n = s.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int minCost = 1e9;
        string temp = "";
        for(int j=i;j<n;j++) {
            temp += s[j];
            if(isPalindrome(temp)) minCost = min(minCost, 1 + f(j+1, s, dp));
        }

        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
    }
};