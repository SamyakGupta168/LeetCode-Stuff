class Solution {
public:
    using ll = long long;
    int maximumLength(vector<int>& nums) {
        map<ll,ll> mp;
        for(auto x : nums) {
            mp[x]++;
        }

        int ans = (mp[1]&1 ? mp[1] : max(0, (int)mp[1] - 1));
        for(auto p : mp) {
            if(p.first == 1) continue;
            ll val = p.first;
            int cnt = 0;
            while(val <= 1e9 && mp[val] >= 2) {
                val *= val;
                cnt++;
            }

            if(val > 1e9) {
                ans = max(ans, 2*cnt - 1);
            } else {
                if(mp[val] == 1) ans = max(ans, 2*cnt + 1);
                else if(mp[val] == 0) ans = max(ans, 2*cnt - 1);
            }
        }

        return ans;
    }
};