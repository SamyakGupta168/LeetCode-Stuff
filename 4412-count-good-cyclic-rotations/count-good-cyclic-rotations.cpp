class Solution {
public:
    using ll = long long;
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        for(auto x : nums) {
            sum += (ll)x;
        }
        ll ps = 0;
        for(int i=0;i<n/2;i++) ps += (ll)nums[i];
        int cnt = 0;
        if(ps > sum - ps) cnt++;
        for(int i=1;i<n;i++) {
            ps -= nums[(i - 1 + n) % n];
            ps += nums[(i + n/2 - 1) % n];
            if(ps > sum - ps) cnt++;
        }
        return cnt;
    }
};