class Solution {
public:
    using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<ll,ll> mp;
        for(auto x : power) mp[x]++;
        vector<pair<ll,ll>> v;
        for(auto p : mp) v.emplace_back(p.first, p.second);

        int m = v.size();
        vector<ll> dp(m, 0);
        dp[0] = v[0].first * v[0].second;
        for(int i=1;i<m;i++) {
            ll val = v[i].first;
            auto it = upper_bound(v.begin(), v.end(), make_pair(val-3, (ll)INT_MAX));
            if(it == v.begin()) {
                dp[i] = max(dp[i-1], v[i].first * v[i].second);
            } else {
                int idx = it - v.begin();
                idx--;
                dp[i] = max(dp[i-1], v[i].first * v[i].second + dp[idx]);
            }
        }

        return dp[m-1];
    }
};