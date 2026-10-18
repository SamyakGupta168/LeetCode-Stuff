class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int del = 0;
        for(int i=1;i<n;i++) {
            if(nums[i] == nums[i-1]) del++;
        }
        return del;
    }
};