class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    ll mod_mul(ll a, ll b) { return (a % mod) * (b % mod) % mod; }

    ll power(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = mod_mul(res, a);
            a = mod_mul(a, a);
            b >>= 1;
        }
        return res;
    }

    // Modular inverse of b
    ll mod_inv(ll b) { return power(b, mod - 2); }

    // Modular division: a / b % mod
    ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)); }

    int countVisiblePeople(int n, int pos, int k) {
        ll p = pos, q = n - pos - 1;
        vector<ll> c1(p + 1), c2(q + 1);
        c1[0] = 1, c2[0] = 1;
        for (ll i = 1; i <= p; i++) {
            c1[i] = mod_div(mod_mul(p - i + 1, c1[i - 1]), i);
        }

        for (ll i = 1; i <= q; i++) {
            c2[i] = mod_div(mod_mul(q - i + 1, c2[i - 1]), i);
        }

        ll ans = 0;
        for (ll x = 0; x <= k; x++) {
            if (x >= 0 && x <= p && k - x >= 0 && k - x <= q) {
                ll temp = mod_mul(c1[x], c2[k - x]);
                ans = (ans + mod_mul(temp, 2)) % mod;
            }
        }

        return ans;
    }
};