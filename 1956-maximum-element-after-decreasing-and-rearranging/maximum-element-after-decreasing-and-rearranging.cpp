class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(auto x : arr) ans = min(ans+1, x);
        return ans;
    }
};