class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            int diff = -1;
            for(int j=i+1;j<n;j++) {
                if(j == i+1) {
                    diff = nums[j] - nums[j-1];
                    continue;
                }
                if(nums[j] - nums[j-1] != diff) break;
                if(nums[j] - nums[j-1] == diff && j-i >= 2) cnt++;
            }
        }

        return cnt;
    }
};