class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int> mp;
        unordered_map<int,int> lastOcc;
        int l = 0, r = 0;
        while(r < n) {
            mp[nums[r]]++;
            lastOcc[nums[r]] = r;
            if(mp.size() < k) {
                r++;
            } else if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[nums[l]]--;
                    if(!mp[nums[l]]) {
                        mp.erase(nums[l]);
                        lastOcc.erase(nums[l]);
                    }
                    l++;
                }
            } 

            if(mp.size() == k) {
                int minIdx = INT_MAX;
                for(auto &p : lastOcc) minIdx = min(minIdx, p.second);
                cnt += minIdx - l + 1;
                r++;
            }
        }

        return cnt; 
    }
};