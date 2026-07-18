class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        string t;
        while(mp[y] != 0) {
            t += y;
            mp[y]--;
        }

        for(auto p : mp) {
            char ch = p.first;
            int cnt = p.second;
            while(cnt != 0) {
                t += ch;
                cnt--;
            }
        }

        return t;
    }
};