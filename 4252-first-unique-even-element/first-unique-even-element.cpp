class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> mp;
        for(auto x : nums) mp[x]++;
        for(auto x : nums) {
            if(mp[x]==1 && x%2==0) return x;
        }
        return -1;
    }
};