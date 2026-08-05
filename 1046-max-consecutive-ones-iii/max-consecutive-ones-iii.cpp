class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, maxLen = 0;
        int l = 0, r = 0;
        while(r < n) {
            if(nums[r] == 0) cnt++;
            while(cnt > k) {
                if(nums[l] == 0) cnt--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};