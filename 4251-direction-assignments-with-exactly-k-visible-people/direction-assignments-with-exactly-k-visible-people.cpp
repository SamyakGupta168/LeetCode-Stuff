class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    /*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll lcm(ll x, ll y) { return (x*y)/__gcd(x, y); }
bool isPrime(ll n){ if(n==1) return false;  for(ll i=2;i*i<=n;i++) { if(n%i==0) return false; } return true; }
/*--------------------------------------------------------------------------------------------------------------------------*/


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