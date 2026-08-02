class Solution {
public:
    using ll = long long;
    int maximumWidth(vector<int>& planks) {
        map<ll,ll> mp;
        for(auto x : planks) mp[x]++;

        vector<pair<ll,ll>> v(mp.begin(), mp.end());
        for(int i=0;i<v.size();i++) {
            auto [x, fx] = v[i];
            for(int j=i+1;j<v.size();j++) {
                auto [y, fy] = v[j];
                mp[x+y] += min(fx, fy);
            }
            mp[2*x] += fx/2;
        }

        int ans = 0;
        for(auto &p : mp) ans = max(ans, (int)p.second);

        return ans;
    }
};