class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int tar) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            unordered_map<int,int> mp;
            for(int j=i;j<n;j++) {
                mp[nums[j]]++;
                if(mp[tar] > (j - i + 1) / 2) cnt++;
            }
        }

        return cnt;
    }
};