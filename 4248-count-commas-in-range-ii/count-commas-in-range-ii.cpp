class Solution {
public:
    using ll = long long;
    ll Msb(ll n) {
        if(n==0) return 0;
        ll pos=0;
        while(n>0) {
            pos++;
            n/=10;
        }
        return pos;
    }

    ll expo(int x) {
        ll val = 1;
        while(x--) {
            val*=10;
        }
        return val;
    }

    long long countCommas(long long n) {
        ll msb = Msb(n);
        msb--;
        ll ans = (n - expo(msb) + 1)*(msb/3);
        msb--;
        while(msb>=3) {
            ans+=(9*expo(msb)*(msb/3));
            msb--;
        }
        return ans;
    }
};