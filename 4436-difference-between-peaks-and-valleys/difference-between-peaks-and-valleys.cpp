class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int diff = 0;
        int n = nums.size();
        for(int i=1;i<n-1;i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) diff+=nums[i];
            else if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) diff-=nums[i];
        }
        return diff;
    }
};