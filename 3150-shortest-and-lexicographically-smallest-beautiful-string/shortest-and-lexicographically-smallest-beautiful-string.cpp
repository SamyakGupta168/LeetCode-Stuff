class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, cnt = 0;
        int len = INT_MAX;
        while(r < n) {
            if(s[r] == '1') cnt++;
            while(cnt == k) {
                len = min(len, r - l + 1);
                if(s[l] == '1') cnt--;
                l++;
            }
            r++;
        }

        if(len == INT_MAX) return "";

        deque<char> temp, ff;
        vector<int> pref(n);
        pref[0] = (s[0] == '1');
        for(int i=1;i<n;i++) pref[i] = pref[i-1] + (s[i] == '1');
        
        for(int i=0;i<len;i++) temp.push_back(s[i]);
        
        if(pref[len-1] == k) {
            ff = temp;
        }

        for(int i=len;i<n;i++) {
            temp.push_back(s[i]);
            temp.pop_front();
            if(pref[i] - pref[i-len] == k && (ff.empty() || temp < ff)) {
                ff = temp;
            }
        }

        string ans;
        for(auto c : ff) ans += c;
        return ans;
    }
};