class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        map<int,int> mp;
        for(int i=0;i<k;i++) {
            mp[nums[i]]++;
            st.insert(nums[i]);
        }

        map<int,int> f;
        for(auto x : st) f[x]++;
        for(int i=k;i<n;i++) {
            mp[nums[i-k]]--;
            mp[nums[i]]++;
            if(!mp[nums[i-k]]) {
                mp.erase(nums[i-k]);
                st.erase(nums[i-k]);
            }
            st.insert(nums[i]);
            for(auto x : st) f[x]++;
        }

        int mx = -1;
        for(auto p : f) {
            if(p.second == 1) mx = p.first;
        }

        return mx;
    }
};