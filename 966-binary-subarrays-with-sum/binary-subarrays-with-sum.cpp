class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pref(n, nums[0]);
        unordered_map<int,int> mp;
        mp[pref[0]]++;
        for(int i=1;i<n;i++) {
            pref[i] = pref[i-1] + nums[i];
            mp[pref[i]]++;
        }
        
        int cnt = 0, prev = 0;
        for(int i=0;i<n;i++) {
            if(mp.count(prev + goal)) cnt += mp[prev + goal];
            prev = pref[i];
            mp[pref[i]]--;
            if(!mp[pref[i]]) mp.erase(pref[i]);
        }

        return cnt;
    }
};