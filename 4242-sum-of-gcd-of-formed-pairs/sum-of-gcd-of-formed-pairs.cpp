class Solution {
public:
    using ll = long long;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> preGcd(n);
        int mx = 0;
        for(int i=0;i<n;i++) {
            mx = max(mx, nums[i]);
            preGcd[i] = __gcd(mx, nums[i]);
        }

        sort(preGcd.begin(), preGcd.end());

        ll ans = 0;
        int l = 0, r = n-1;
        while(l < r) {
            ans += (ll)__gcd(preGcd[l], preGcd[r]);
            l++, r--;
        }

        return ans;
    }
};