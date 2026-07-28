class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> f(26);
        for(auto x : s) f[x - 'a']++;
        string ans(n, '*');
        int idx = 0, x = 0;
        for(auto cnt : f) {
            if(cnt&1) {
                ans[n/2] = char(x + 'a');
                cnt--;
            }
            
            while(cnt) {
                  ans[idx] = char(x + 'a');
                  ans[n-idx-1] = char(x + 'a');
                  idx++;
                  cnt-=2;
                }
                x++;
            }
            return ans;
 }
 };