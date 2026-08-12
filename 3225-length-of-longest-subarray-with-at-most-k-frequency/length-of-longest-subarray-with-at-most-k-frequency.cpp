class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> ms;
        map<int,int> mp;
        int l = 0, r = 0, maxLen = 0;
        while(r < n) {
            if(mp.count(nums[r])) {
                ms.erase(ms.find(mp[nums[r]]));
            }
            mp[nums[r]]++;
            ms.insert(mp[nums[r]]);
            if(*ms.rbegin() > k) {
                ms.erase(ms.find(mp[nums[l]]));
                mp[nums[l]]--;
                if(mp[nums[l]]) ms.insert(mp[nums[l]]);
                else mp.erase(nums[l]);
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};