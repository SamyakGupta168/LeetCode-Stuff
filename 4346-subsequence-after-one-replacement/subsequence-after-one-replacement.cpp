class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = t.size();
        vector<int> prev(2, 0), curr(2, 0);
        prev[1] = 1;
        prev[0] = (s[0] == t[0]);
        for(int i=1;i<n;i++) {
            int idx1 = prev[1];
            if(idx1 == s.size()) {
                curr[1] = idx1;
            } else if(s[idx1] == t[i]) {
                curr[1] = idx1 + 1;
            } else {
                idx1 = max(idx1, prev[0] + 1);
                curr[1] = idx1;
            }

            int idx2 = prev[0];
            if(idx2 == s.size()) {
                curr[0] = idx2;
            } else if(s[idx2] == t[i]) {
                curr[0] = idx2 + 1;
            } else {
                curr[0] = idx2;
            }

            prev = curr;
        }

        return prev[1] == s.size();
    }
};