class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s.insert(s.begin(), '1');
        s += '1';
        vector<int> ps((int)s.size());
        for(int i=1;i<s.size();i++) ps[i] = ps[i-1] + (s[i] != s[i-1]);
        vector<int> cz(s.size(), 0);
        cz[0] = (s[0] == '0');
        for(int i=1;i<s.size();i++) cz[i] = cz[i-1] + (s[i] == '0'); 

        if(ps.back() == 4) return s.size() - 2;

        unordered_map<int,int> mp;
        int zeros = 0;
        int st = -1, end = -1;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                if(mp.count(ps[i] - 4)) {
                    int idx = mp[ps[i] - 4];
                    int cnt = cz[i] - cz[idx];
                    if(i == s.size() - 1 || idx == 0) {
                        if(cnt > zeros) {
                            st = mp[ps[i] - 4], end = i;
                            if(mp[ps[i] - 4] == 0) st++;
                            else end--;
                            zeros = cnt;
                        }
                    }
                    else if(cnt > zeros) {
                        st = mp[ps[i] - 4];
                        end = i;
                        zeros = cnt;
                    }
                }
            }
            if(!mp.count(ps[i])) mp[ps[i]] = i;
        }

        int ans = end - st + 1;
        if(st == -1) {
            ans = count(s.begin() + 1, s.end() - 1, '1');
        } else {
            ans += count(s.begin() + 1, s.begin() + st, '1');
            ans += count(s.begin() + end + 1, s.end() - 1, '1');
        }
        
        return ans;
    }
};