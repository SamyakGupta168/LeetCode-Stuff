class Solution {
public:
    int f(int i, int flag, vector<pair<int,int>>&a, vector<vector<int>>&dp) {
        int n = a.size();
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];

        int maxi = 0;
        if(flag) {
            maxi = max(maxi, a[i].second*a[i].first + f(i+1, 0, a, dp));
            maxi = max(maxi, f(i+1, 1, a, dp));
        } else {
            maxi = max(maxi, f(i+1, 1, a, dp));
            if(a[i].first != a[i-1].first + 1) {
                maxi = max(maxi, a[i].second*a[i].first + f(i+1, 0, a, dp));
            }
        }

        return dp[i][flag] = maxi;
    }

    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto x : nums) mp[x]++;

        vector<pair<int,int>> a;
        for(auto p : mp) {
            a.push_back({p.first, p.second});
        }

        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, a, dp);
    }
};