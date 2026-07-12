class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll rem = k, p = 1, cost = 0;
        for(int i=0;i<n;i++) {
            if(rem >= nums[i]) {
                rem -= nums[i];
            } else {
                ll x = (nums[i] - rem + k - 1) / k;
                cost += mod_mul(x, p-1, mod);
                cost %= mod;
                if(x%2 == 0) {
                    cost += mod_mul(x/2, x+1, mod);
                } else {
                    cost += mod_mul(x, (x+1)/2, mod);
                }
                cost %= mod;
                rem += x*k;
                p += x;
                rem -= nums[i];
            }
        }

        return (int)cost;
    }
};