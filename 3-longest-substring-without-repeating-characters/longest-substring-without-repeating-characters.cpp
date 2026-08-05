class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int maxLen = 0;
        int l = 0, r = 0;
        while(r < n) {
            mp[s[r]]++;
            if(mp.size() == r - l + 1) {
                maxLen = max(maxLen, r - l + 1);
            } else {
                mp[s[l]]--;
                if(!mp[s[l]]) mp.erase(s[l]);
                l++;
            }
            r++;
        }

        return maxLen;
    }
};