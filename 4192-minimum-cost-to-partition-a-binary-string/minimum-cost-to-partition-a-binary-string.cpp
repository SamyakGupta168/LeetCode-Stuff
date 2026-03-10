class Solution {
public:
    using ll = long long;
    ll solve(string &s, ll ec, ll fc, vector<ll>&ps, ll st, ll end) {
        ll len = end-st+1;
        ll cnt = ps[end] - ((st==0) ? 0 : ps[st-1]);
        if(len&1) {
            if(cnt==0) return fc;
            else return 1ll * len * cnt * ec;
        }
        ll cost = ((cnt==0) ? fc : 1ll * len * cnt * ec);
        ll c1 = solve(s, ec, fc, ps, st, st + (len/2) - 1);
        ll c2 = solve(s, ec, fc, ps, st + (len/2), end);
        cost = min(cost, c1 + c2);
        return cost;
    }

    long long minCost(string s, int ec, int fc) {
        int n = s.size();
        vector<ll> ps(n);
        ps[0] = (s[0]=='1');
        for(int i=1;i<n;i++) {
            ps[i] = ps[i-1] + (s[i]=='1');
        }

        return 1ll * solve(s, ec, fc, ps, 0, n-1);
    }
};