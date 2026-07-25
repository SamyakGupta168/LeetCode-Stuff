class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int p = 1, rp = 1;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                ans = max(ans, 0);
                p = 1;
            } else {
                p *= nums[i];
                ans = max(ans, p);
            }

            if(nums[n-i-1] == 0) {
                ans = max(ans, 0);
                rp = 1;
            } else {
                rp *= nums[n-i-1];
                ans = max(ans, rp);
            }
        }

        return ans;
    }
};