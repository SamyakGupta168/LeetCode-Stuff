class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto &s : words) {
            int wt = 0;
            for(auto ch : s) wt += weights[(ch - 'a')];
            wt %= 26;
            ans += char(('z' - 'a' - wt) + 'a');
        }
        return ans;
    }
};