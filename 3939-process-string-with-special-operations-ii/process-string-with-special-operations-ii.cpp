class Solution {
public:
    using ll = long long;

    char processStr(string s, long long k) {
        int n = s.size();
        ll len = 0;
        for(auto x : s) {
            if(x == '*') {
                if(len) len--;
            }
            else if(x == '#') len *= 2;
            else if(x == '%') continue;
            else len++;
        }  

        if(k + 1 > len) return '.';

        for(int i=n-1;i>=0;i--) {
            if(s[i] == '*') len++;
            else if(s[i] == '#') {
                if(k + 1 > len/2) {
                    k -= len/2;
                }
                len = len/2;
            } else if(s[i] == '%') {
                k = len - k - 1;
            } else {
                if(k + 1 == len) return s[i];
                else len--;
            }
        }

        return '.';
    }
};