class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
    ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
    ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

    int countVisiblePeople(int n, int pos, int k) {
        ll p = pos, q = n - pos - 1;
        vector<ll> c1(p + 1), c2(q + 1);
        c1[0] = 1, c2[0] = 1;
        for (ll i = 1; i <= p; i++) {
            c1[i] = mod_div(mod_mul(p - i + 1, c1[i - 1], mod), i, mod);
        }

        for (ll i = 1; i <= q; i++) {
            c2[i] = mod_div(mod_mul(q - i + 1, c2[i - 1], mod), i, mod);
        }

        ll ans = 0;
        for (ll x = 0; x <= k; x++) {
            if (x >= 0 && x <= p && k - x >= 0 && k - x <= q) {
                ll temp = mod_mul(c1[x], c2[k - x], mod);
                ans = (ans + mod_mul(temp, 2, mod)) % mod;
            }
        }

        return ans;
    }
};