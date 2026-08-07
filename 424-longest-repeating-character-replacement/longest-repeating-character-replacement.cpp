class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26);
        int maxLen = 0;
        int l = 0, r = 0;
        while(r < n) {
            hash[s[r] - 'A']++;
            int maxFreq = 0;
            for(auto x : hash) maxFreq = max(maxFreq, x);
            if(r - l + 1 - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    } 
};