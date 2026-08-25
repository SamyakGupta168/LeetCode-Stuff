class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(auto x : nums) st.insert(x);
        int ans = k;
        while(st.count(ans)) ans += k;
        return ans;
    }
};