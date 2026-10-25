class Solution {
public:
    using ll = long long;
    ll f(ll x) {
        vector<ll> dd;
        if(x == 0) dd.push_back(0);
        ll temp = x;
        while(temp > 0) {
            ll d = temp % 10;
            dd.push_back(d);
            temp /= 10;
        }

        sort(dd.begin(), dd.end());
        ll val = 0;
        for(int i=(ll)dd.size()-1;i>=0;i--) {
            val*=10;
            val += dd[i];
        }
        return val;
    }
    
    long long maximizeSum(vector<int>& nums, int k) {
        ll n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ll> inc;
        for(int i=n-1;i>=0;i--) {
            ll x = f(nums[i]);
            inc.push_back(max(0LL, x - nums[i]));
        }

        ll ans = 0;
        for(auto x : nums) ans += (ll)x;
        sort(inc.begin(), inc.end());
        ll op = 0;
        for(int i=(ll)inc.size()-1;i>=0;i--) {
            if(inc[i]) op++;
            ans += inc[i];
            if(op == k) break;
        }

        return ans;
    }
};