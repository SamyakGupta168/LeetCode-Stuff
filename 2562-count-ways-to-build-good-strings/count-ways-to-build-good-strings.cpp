class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll> dp(high+1, 0);
        dp[0] = 1;
        for(int i=1;i<=high;i++) {
            if(i >= one) dp[i] += dp[i - one];
            if(i >= zero) dp[i] += dp[i - zero];
            dp[i] %= mod;
        }

        ll ans = 0;
        for(int i=low;i<=high;i++) {
            ans += dp[i];
            ans %= mod;
        }

        return (int)ans;
    }
};