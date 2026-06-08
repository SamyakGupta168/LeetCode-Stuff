class Solution {
public:
    bool check(string &s1, string &s2) {
        if(s1.size() + 1 != s2.size()) return false;
        int ind = 0;
        for(auto ch : s2) {
            if(ind == s1.size()) break;
            if(ch == s1[ind]) ind++;
        }

        return (ind == s1.size());
    }

    int f(int idx, int next, vector<string>&words, vector<vector<int>>&dp) {
        int n = words.size();
        if(idx < 0) return 0;
        if(dp[idx][next] != -1) return dp[idx][next];

        int notTake = 0 + f(idx-1, next, words, dp);
        int take = 0;
        if(next == n || check(words[idx], words[next])) {
            take = 1 + f(idx-1, idx, words, dp);
        }
        
        return dp[idx][next] = max(take, notTake);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&] (auto &s1, auto &s2) -> bool {
            return (s1.size() < s2.size());
        });

        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));
        for(int i=1;i<=n;i++) {
            for(int next=i+1;next<=n+1;next++) {
                int notTake = dp[i-1][next];
                int take = 0;
                if(next == n+1 || check(words[i-1], words[next-1])) {
                    take = 1 + dp[i-1][i];
                }
                dp[i][next] = max(take, notTake);
            }
        }

        return dp[n][n+1];
    }
};