class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0 && pos <= i && pos != nums.size() - 1) return false;
            pos = max(pos, nums[i] + i);
        }

        return true;
    }
};