class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int i=n-1;i>=0;i--) {
            for(int prevIdx=0;prevIdx<=i;prevIdx++) {
                int len = next[prevIdx];
                if(prevIdx == 0 || nums[i] > nums[prevIdx-1]) {
                    len = max(len, 1 + next[i+1]);
                }
                curr[prevIdx] = len;
            }
            next = curr;
        }

        return next[0];
    }
};