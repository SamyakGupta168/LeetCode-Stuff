class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int k = 2;
        multiset<int> ms;
        unordered_map<int,int> mp;
        int l = 0, r = 0, maxLen = 0;
        while(r < n) {
            if(mp.count(s[r])) {
                ms.erase(ms.find(mp[s[r]]));
            }
            mp[s[r]]++;
            ms.insert(mp[s[r]]);
            if(*ms.rbegin() > k) {
                ms.erase(ms.find(mp[s[l]]));
                mp[s[l]]--;
                if(mp[s[l]]) ms.insert(mp[s[l]]);
                else mp.erase(s[l]);
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};