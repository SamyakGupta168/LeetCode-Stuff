class Solution {
public:
    using ll = long long;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> preGcd(n, 0);
        int pmax = -1;
        for(int i=0;i<n;i++) {
            pmax=max(pmax, nums[i]);
            preGcd[i] = __gcd(nums[i], pmax);
        }
        sort(preGcd.begin(), preGcd.end());
        int l = 0, r = n-1;
        ll ans = 0;
        while(l < r) {
            ans+=__gcd(preGcd[l++], preGcd[r--]);
        }
        return ans;
    }
};