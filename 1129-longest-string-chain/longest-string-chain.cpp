class Solution {
public:
    bool check(string &s1, string &s2) {
        if(s1.size() != (s2.size() + 1)) return false;
        int i = 0, j = 0;
        while(i<s2.size() && j<s1.size()) {
            if(s2[i] == s1[j]) i++;
            j++;
        }
        return (i == s2.size());
    }

    int f(int idx, vector<string>& words, vector<int>&dp, int V) {
        if(idx == V-1) return 1;
        if(dp[idx] != -1) return dp[idx];

        int maxi = 1;
        for(int i=idx+1;i<V;i++) {
            if(check(words[idx], words[i])) {
                maxi = max(maxi, 1 + f(i, words, dp, V));
            }
        }
        return dp[idx] = maxi;
    }

    int longestStrChain(vector<string>& words) {
        int V = words.size();
        
        sort(words.begin(), words.end(), [&] (auto &s1, auto &s2) -> bool {
            return (s1.size() > s2.size());
        });

        int ans = 0;
        vector<int> dp(V, -1);
        for(int i=0;i<V;i++) {
            if(dp[i] == -1) {
                ans = max(ans, f(i, words, dp, V));
            }
        }

        return ans;
        
    }
};