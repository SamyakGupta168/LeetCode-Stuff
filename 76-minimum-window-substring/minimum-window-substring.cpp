class Solution {
public: 
    bool check(map<char,int>&org, map<char,int>&mp) {
        for(auto &p : org) {
            if(!mp.count(p.first)) return false;
            if(mp[p.first] < p.second) return false;
        }
        return true;
    } 

    string minWindow(string s, string t) {
        map<char,int> org;
        for(auto ch : t) org[ch]++;
        int minLen = INT_MAX;
        int idx = -1;
        int n = s.size();
        map<char,int> mp;
        int l = 0, r = 0;
        while(r < n) {
            mp[s[r]]++;
            while(check(org, mp)) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    idx = l;
                }
                mp[s[l]]--;
                if(!mp[s[l]]) mp.erase(s[l]);
                l++;
            }
            r++;
        }

        if(idx == -1) return "";
        return s.substr(idx, minLen);
    }
};