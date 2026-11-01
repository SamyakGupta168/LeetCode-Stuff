class Solution {
public:
    using ll = long long;
    long long minimumMaxValue(int n, int idx, int val) {
        ll mn = INT_MAX;
        ll nn = n;
        ll vv = val;
        for(ll i=1;i*i<=vv;i++) {
            if(vv % i == 0) {
                if(i != 1) mn = min(mn, i);
                if(vv/i != 1) mn = min(mn, vv/i);
            }
        }

        ll prev = 0;
        if(vv % 2 == 0) {
            prev = vv/2 - 1;
        } else {
            if(vv != mn) {
                prev += 1;
                prev += ((vv-mn)/2 - 1);
            } 
        }

        if(prev < idx) return -1;
        
        ll rem = nn - (ll)idx - 1;
        if(rem == 0) return vv;

        ll ans = -1;
        if(vv % 2 == 0) {
            ans = (vv/2 + rem) * 2;
        } else {
            vv += mn; rem -= 1;
        }

        ans = (vv/2 + rem) * 2;
        return ans;
    }
};