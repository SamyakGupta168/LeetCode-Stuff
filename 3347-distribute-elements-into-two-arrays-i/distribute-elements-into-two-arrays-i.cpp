class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 2;
        while(i < n) {
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
            i++;
        }

        vector<int> res;
        for(auto x : arr1) res.push_back(x);
        for(auto x : arr2) res.push_back(x);
        
        return res;
    }
};