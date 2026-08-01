class Solution {
public:
    using ll = long long;
    long long minInitialStrength(vector<int>& mon, vector<vector<int>>& b) {
        int n = mon.size();
        vector<ll> diff(n, 0);
        for(auto &x : b) {
            int l = x[0], r =x[1], v = x[2];
            diff[l] += v;
            if(r+1 < n) diff[r+1] -= v;
        }

        for(int i=1;i<n;i++) diff[i] += diff[i-1];

        ll ans = 0;
        for(int i=n-1;i>=0;i--) {
            if(!ans) {
                if(diff[i] >= mon[i]) continue;
                else ans = mon[i] - diff[i];
            } else {
                ans += mon[i];
            }
        }

        return ans;
    }
};