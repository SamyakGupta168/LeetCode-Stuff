class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=1;i<n;i+=2) {
            string s1 = to_string(nums[i-1]);
            string s2 = to_string(nums[i]);
            string res = s1 + s2;
            int val = stoi(res);
            ans = min(ans, val);
        }
        return ans;
    }
};