class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for(int r=0;r<n;r++) {
            int opr = r;
            if(r > 0) {
                char c = s[0];
                s = s.substr(1);
                s += c;
            }
            for(int i=0;i<n/2;i++) {
                int d1 = (s[i] >= s[n-i-1] ? s[i] - s[n-i-1] : s[n-i-1] - s[i]);
                opr += min(d1, 26 - d1);
            }
            ans = min(ans, opr);
        }

        return ans;
    }
};