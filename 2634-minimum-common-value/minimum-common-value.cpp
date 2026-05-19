class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1, mp2;
        for(auto x : nums1) mp1[x]++;
        for(auto x : nums2) mp2[x]++;

        for(auto p : mp1) {
            if(mp2.count(p.first)) return p.first;
        }

        return -1;
    }
};