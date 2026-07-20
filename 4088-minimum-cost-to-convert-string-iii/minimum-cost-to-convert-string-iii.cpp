class Solution {
public:
    int minCost(string src, string tar, vector<vector<string>>& rules, vector<int>& costs) {
        int n = src.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] == INT_MAX) continue;

            if(src[i] == tar[i]) dp[i+1] = min(dp[i+1], dp[i]);

            for(int j=0;j<rules.size();j++) { // Check all the rules
                string &pat = rules[j][0];
                string &rep = rules[j][1];

                int l = pat.size();
                if(i + l > n) continue;

                int c = 0;
                bool pos = true;
                for(int k=0;k<l;k++) {
                    if(pat[k] == '*') c++;
                    else if(pat[k] != src[i+k]) {
                        pos = false;
                        break;
                    }
                    if(rep[k] != tar[i+k]) {
                        pos = false;
                        break;
                    }
                }

                if(pos) {
                    int finalCost = dp[i] + costs[j] + c;
                    dp[i+l] = min(dp[i+l], finalCost);
                }
            }
        }

        return (dp[n] != INT_MAX ? dp[n] : -1);
    }
};