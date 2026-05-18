class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int co = count(s.begin(), s.end(), '1');
        int cz = count(s.begin(), s.end(), '0');
        if(co == n || cz == n) return 0;
        int ans = min(cz, co-1);
        if(s[0] == '1' && s[n-1] == '1') ans = min(ans, co-2);
        return ans;
    }
};