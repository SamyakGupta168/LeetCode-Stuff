class Solution {
public:
    using ll = long long;
    long long maximumValue(int n, int s, int m) {
        ll ans = s;
        if(n&1) {
            if(n > 1) ans = (ll)s + (ll)((n-1)/2)*m - ((n-1)/2 - 1);
        } else {
            ans = (ll)s + (ll)(n/2)*m - (n/2 - 1);
        }

        return ans;
    }
};