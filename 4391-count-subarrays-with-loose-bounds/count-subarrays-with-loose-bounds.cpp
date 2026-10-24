class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int mini, int maxi) {
        ll n = nums.size();
        ll cnt = 0;
        ll l = 0, r = 0;
        while(r < n) {
            if(nums[r] > maxi || nums[r] < mini) {
                l = r+1;
                r++;
                continue;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};