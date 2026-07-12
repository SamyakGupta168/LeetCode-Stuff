class Solution {
public:
    int f(int i, string &s, set<string>&dic, vector<int>&dp) {
        int n = s.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int notTake = 1 + f(i+1, s, dic, dp);
        int take = 1e9;
        string temp = "";
        for(int j=i;j<n;j++) {
            temp += s[j];
            if(dic.count(temp)) {
                take = min(take, f(j+1, s, dic, dp));
            }
        }

        return dp[i] = min(take, notTake);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> dic;
        for(auto &str : dictionary) dic.insert(str);
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dic, dp);
    }
};