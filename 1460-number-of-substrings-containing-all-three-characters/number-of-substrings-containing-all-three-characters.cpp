class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int l = 0, r = 0, cnt = 0;
        while(r < n) {
            mp[s[r]]++;
            while(mp.size() == 3) {
                cnt += n - r;
                mp[s[l]]--;
                if(!mp[s[l]]) mp.erase(s[l]);
                l++;
            }
            r++;
        }

        return cnt;
    }
};