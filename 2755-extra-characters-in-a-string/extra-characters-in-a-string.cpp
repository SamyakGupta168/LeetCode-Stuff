class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> dic;
        for(auto &str : dictionary) dic.insert(str);
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--) {
            int notTake = 1 + dp[i+1];
            int take = 1e9;
            string temp = "";
            for(int j=i;j<n;j++) {
                temp += s[j];
                if(dic.count(temp)) {
                    take = min(take, dp[j+1]);
                }
            }
            dp[i] = min(take, notTake);
        }

        return dp[0];
    }
};