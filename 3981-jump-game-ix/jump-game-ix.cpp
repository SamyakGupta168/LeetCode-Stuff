class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, nums[0]), rightMin(n, INT_MAX);
        for(int i=1;i<n;i++) leftMax[i] = max(nums[i], leftMax[i-1]);
        for(int i=n-2;i>=0;i--) rightMin[i] = min(nums[i+1], rightMin[i+1]);

        vector<int> ans(n, -1);
        ans[n-1] = leftMax[n-1];
        for(int i=n-2;i>=0;i--) {
            if(leftMax[i] <= rightMin[i]) ans[i] = leftMax[i];
            else ans[i] = ans[i+1];
        }

        return ans;
    }
};