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

    int f(int len, int idx, vector<vector<int>>&v, vector<string>& words, vector<vector<int>>&dp) {
        if(len-1 < 0) return 1;
        if(v[len-1].empty()) return 1;
        if(dp[len][idx] != -1) return dp[len][idx];

        int maxi = 1;
        for(auto &ind : v[len-1]) {
            if(check(words[idx], words[ind])) {
                maxi = max(maxi, 1 + f(len-1, ind, v, words, dp));
            }
        }
        return dp[len][idx] = maxi;
    }

    int longestStrChain(vector<string>& words) {
        int V = words.size();
        int maxHeight = 0, currHeight = 0;
        vector<vector<int>> v(16+1);
        for(int i=0;i<V;i++) {
            v[words[i].size()].push_back(i);
        }
        
        vector<vector<int>> dp(16+1, vector<int>(V, -1));
        int ans = -1;
        for(int i=16;i>=1;i--) {
            for(int j=0;j<v[i].size();j++) {
                if(dp[i][v[i][j]] == -1) {
                    ans = max(ans, f(i, v[i][j], v, words, dp));
                }
            }
        }

        return ans;
        
    }
};