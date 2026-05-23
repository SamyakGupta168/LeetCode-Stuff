class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int idx = -1, cnt = 0;
        for(int i=1;i<n;i++) {
            if(nums[i-1] > nums[i]) {
                idx = i;
                cnt++;
            }
        }

        if(cnt == 0) return true;
        if(cnt > 1) return false;
        return nums[0] >= nums[n-1];
    }
};