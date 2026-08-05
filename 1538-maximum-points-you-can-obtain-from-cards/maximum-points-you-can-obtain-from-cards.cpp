class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int totSum = 0;
        int l = 0, r = 0;
        int cur = 0, minSum = INT_MAX;
        while(r < n) {
            cur += nums[r];
            if(r - l + 1 > n-k) {
                cur -= nums[l];
                l++;
            } 
            if(r - l + 1 == n-k) {
                minSum = min(minSum, cur);
            }
            totSum += nums[r];
            r++;
        }

        return totSum - minSum;
    }
};