class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, i = 1;
        for(auto c : s) {
            ans += i * ('z' - c + 1);
            i++;
        }

        return ans;
    }
};