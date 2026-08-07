class Solution {
public:
    int cntOfSubarray(int k, vector<int>&nums, vector<int>&pref) {
        if(k < 0) return 0;
        int n = nums.size();
        int prev = 0, cnt = 0;
        for(int i=0;i<n;i++) {
            int idx = lower_bound(pref.begin(), pref.end(), prev + k + 1) - pref.begin();
            prev = pref[i];
            cnt += idx - i;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pref(n, nums[0]);
        for(int i=1;i<n;i++) pref[i] = pref[i-1] + nums[i];

        return cntOfSubarray(goal, nums, pref) - cntOfSubarray(goal-1, nums, pref);
    }
};