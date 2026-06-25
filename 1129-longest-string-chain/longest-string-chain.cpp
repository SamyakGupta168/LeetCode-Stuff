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

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&] (auto &s1, auto &s2) -> bool {
            return s1.size() < s2.size();
        });

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n;i>=1;i--) {
            for(int j=i;j>=0;j--) { 
                int take = 0;
                if(j == 0 || check(words[i-1], words[j-1])) {
                    take = 1 + dp[i+1][i];
                }
                int notTake = dp[i+1][j];
                dp[i][j] = max(take, notTake);
            }
        }

        return dp[1][0];
    }
};