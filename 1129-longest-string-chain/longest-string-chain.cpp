class Solution {
public:
    bool check(string &s1, string &s2) {
        if(s1.size() != s2.size() + 1) return false;
        int i1 = 0, i2 = 0;
        while(i1 < s1.size() && i2 < s2.size()) {
            if(s1[i1] == s2[i2]) i2++;
            i1++;
        }
        return (i2 == s2.size());
    }

    int f(int i, int prev, vector<string>&words, vector<vector<int>>&dp) {
        int n = words.size();
        if(i == n+1) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];

        int take = 0;
        if(prev == 0 || check(words[i-1], words[prev-1])) {
            take = 1 + f(i+1, i, words, dp);
        }
        int notTake = f(i+1, prev, words, dp);
        return dp[i][prev] = max(take, notTake);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&] (auto &s1, auto &s2) -> bool {
            return s1.size() < s2.size();
        });

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, 0, words, dp);
    }
};