class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        if(n > 2) {
            for(int i=0;i<n;i++) {
            vector<int> a;
            for(int j=0;j<n;j++) {
                if(j != i) a.push_back(nums[j]);
            }
            vector<int> pref(n-1, 0), suff(n-1, 0);
            pref[0] = a[0];
            for(int j=1;j<n-1;j++) {
                pref[j] = __gcd(a[j], pref[j-1]);
            }
            suff[n-2] = a[n-2];
            for(int j=n-3;j>=0;j--) {
                suff[j] = __gcd(a[j], suff[j+1]);
            }
            int cnt = 0;
            for(int j=0;j<n-2;j++) {
                cnt += (pref[j] == suff[j+1]);
            }
            mx = max(mx, cnt);
        }
        }

        vector<int> pref(n), suff(n);
        pref[0] = nums[0], suff[n-1] = nums[n-1];
        for(int i=1;i<n;i++) pref[i] = __gcd(nums[i], pref[i-1]);
        for(int i=n-2;i>=0;i--) suff[i] = __gcd(nums[i], suff[i+1]);
        int cnt = 0;
        for(int i=0;i<n-1;i++) {
            cnt += (pref[i] == suff[i+1]);
        }
        mx = max(mx, cnt);
        return mx;
    }
};