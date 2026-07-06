class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        if(mx == 1) return (int)1e9 + 5;
        ll maxScore = 0, k = INT_MAX;
        vector<ll> divs = sieve(mx);
        for(auto p : divs) {
            ll maxDiff = INT_MIN, diff = 0;
            for(int i=0;i<n;i++) {
                diff += (nums[i] % p == 0 ? nums[i] : -nums[i]);
                maxDiff = max(maxDiff, diff);
                if(diff < 0) diff = 0;
            }
            if(maxScore == maxDiff) k = min(k, p);
            if(maxDiff > maxScore) {
                maxScore = maxDiff;
                k = p;
            }
        }


        return (int)((maxScore * k) % mod);
    }
};