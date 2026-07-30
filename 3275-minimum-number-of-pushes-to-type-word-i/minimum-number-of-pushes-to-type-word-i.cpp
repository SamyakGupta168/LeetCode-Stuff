class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26);
        for(auto x : word) f[x - 'a']++;
        sort(f.rbegin(), f.rend());

        int cnt = 0, sc = 0, ans = 0;
        for(auto x : f) {
            if(cnt % 8 == 0) sc++;
            ans += x * sc;
            cnt++;
        }

        return ans;
    }
};