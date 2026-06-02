class Solution {
public:

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned long long> prev(m+1, 0), curr(m+1, 0);

        for(int j=0;j<=m;j++) prev[j] = 0;
        prev[0] = 1, curr[0] = 1;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1] + prev[j];
                    continue;
                }
                curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[m];
    }
};