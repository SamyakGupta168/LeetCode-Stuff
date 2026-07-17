class Solution {
public:
    using ll = long long;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<ll> cnt(m+1, 0);
        for(auto x : nums) cnt[x]++;

        for(int i=1;i<=m;i++) {
            for(int j=2*i;j<=m;j+=i) {
                cnt[i] += cnt[j];
            }
        }

        for(int i=1;i<=m;i++) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }

        for(int i=m;i>=1;i--) {
            for(int j=2*i;j<=m;j+=i) {
                cnt[i] -= cnt[j];
            }
        }

        for(int i=1;i<=m;i++) {
            cnt[i] += cnt[i-1];
        }

        vector<int> ans;
        for(auto q : queries) {
            q++;
            int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
            ans.push_back(pos);
        }

        return ans;
    }
};