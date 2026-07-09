class Solution {
public:
    using ll = long long;
    const ll mod = 1000000007;
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}

    ll dig(ll n) {
        if(n == 0) return 1;
        ll cnt = 0;
        while(n > 0) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> digCnt(n, 0);
        digCnt[0] = (s[0] != '0');
        vector<ll> ps(n, 0);
        ps[0] = (s[0] - '0');
        for(int i=1;i<n;i++) {
            ps[i] = ps[i-1] + (s[i] - '0');
            digCnt[i] = digCnt[i-1] + (s[i] != '0');
        }

        vector<ll> pref(n, 0);
        ll val = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                pref[i] = val;
                continue;
            }
            if(!val) val = s[i] - '0';
            else val = mod_add(mod_mul(val, 10, mod), s[i] - '0', mod);
            pref[i] = val;
        }

        vector<int> ans;
        for(auto &x : queries) {
            int l = x[0], r = x[1];
            ll sum = ps[r] - (l-1 >= 0 ? ps[l-1] : 0);
            ll x1 = pref[r];
            ll x2 = (l-1 >= 0 ? mod_mul(pref[l-1], expo(10, digCnt[r] - digCnt[l-1], mod), mod) : 0);
            ll p = x1 - x2;
            int val = mod_mul(p, sum, mod);
            ans.push_back(val);
        }

        return ans;
    }
};