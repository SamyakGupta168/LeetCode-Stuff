class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int,int> mp;
        int pref = nums[0];
        mp[pref]++;
        for(int i=1;i<n;i++) {
            pref += nums[i];
            mp[pref]++;
        }
        
        int cnt = 0, prev = 0;
        for(int i=0;i<n;i++) {
            if(mp.count(prev + goal)) cnt += mp[prev + goal];
            prev += nums[i];
            mp[prev]--;
            if(!mp[prev]) mp.erase(prev);
        }

        return cnt;
    }
};