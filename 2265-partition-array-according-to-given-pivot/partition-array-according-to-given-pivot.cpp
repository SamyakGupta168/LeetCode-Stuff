class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int cnt = 0;
        vector<int> res;
        for(int i=0;i<n;i++) {
            if(nums[i] < pivot) res.push_back(nums[i]);
            if(pivot == nums[i]) cnt++;
        }

        while(cnt--) res.push_back(pivot);

        for(int i=0;i<n;i++) {
            if(nums[i] > pivot) res.push_back(nums[i]);
        }

        return res;
    }
};