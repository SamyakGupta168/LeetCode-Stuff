class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int p1 = nums[0] * nums[1], p2 = nums[n-1] * nums[n-2], p3 = nums[0] * nums[n-1];
        for(int i=0;i<n;i++) {
            if(i > 1) ans = max(ans, nums[i] * p1);
            if(i < n-2) ans = max(ans, nums[i] * p2);
            if(i != 0 && i != n-1) ans = max(ans, nums[i] * p3);
        }

        return ans;
    }
};