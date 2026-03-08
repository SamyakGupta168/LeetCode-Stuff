class Solution {
public:
    using ll = long long;
    using ld = long double;
    ll mod = 1e9 + 7;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ps(n, 0), sp(n, -1);
        for(int i=1;i<n;i++) {
            ps[i] = ps[i-1] + nums[i-1];
        }
        // vector<int> isMod(n, 0);
        sp[n-1]=1;
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i=n-2;i>=0;i--) {
            if(sp[i+1]<=(ps[i]/(ll)nums[i+1])) {
                sp[i] = sp[i+1]*nums[i+1];
            } else break;
        }
        
        for(int i=0;i<n;i++) {
            if(sp[i]!=-1) {
                if(ps[i]==sp[i]) return i;
            }
        }
        return -1;
    }
};