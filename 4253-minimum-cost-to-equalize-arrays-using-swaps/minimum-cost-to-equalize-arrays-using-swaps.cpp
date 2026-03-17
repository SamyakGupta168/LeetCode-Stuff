class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 0;
        map<int,int> mp1, mp2;
        for(auto x : nums1) {
            mp1[x] = 0, mp2[x] = 0;
        }
        for(auto x : nums2) {
            mp1[x] = 0, mp2[x] = 0;
        }
        for(auto x : nums1) mp1[x]++;
        for(auto x : nums2) mp2[x]++;

        for(auto p : mp1) {
            if(abs(mp1[p.first]-mp2[p.first])&1) return -1;
            ans+=abs(mp1[p.first]-mp2[p.first])/2;
        }
        ans/=2;
        return ans;
    }
};