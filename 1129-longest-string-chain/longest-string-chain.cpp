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

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&] (auto &s1, auto &s2) -> bool {
            return (s1.size() < s2.size());
        });

        vector<int> dp(n, 1);
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(check(words[prev], words[i])) dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};