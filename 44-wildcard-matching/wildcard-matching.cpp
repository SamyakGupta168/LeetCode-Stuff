class Solution {
public:

    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        prev[0] = 1;
        for(int j=1;j<=m;j++) prev[j] = 0;

        for(int i=1;i<=n;i++) {
            curr[0] = (p[i-1] == '*')&&prev[0];
            for(int j=1;j<=m;j++) {
                if((p[i-1] == s[j-1]) || (p[i-1] == '?')) curr[j] = prev[j-1];
                else if(p[i-1] == '*') curr[j] = prev[j] | curr[j-1];
                else curr[j] = 0;
            }
            prev = curr;
        }

        return prev[m];
    }
};