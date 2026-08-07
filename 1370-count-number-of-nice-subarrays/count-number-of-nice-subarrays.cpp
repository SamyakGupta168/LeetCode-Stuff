class Solution {
public:
    int f(vector<int>&nums, int k) {
        int n = nums.size();
        int ans = 0, cnt = 0;
        int l = 0, r = 0;
        while(r < n) {
            cnt += (nums[r] & 1);
            while(cnt > k) {
                cnt -= (nums[l] & 1);
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};