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
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1;i>=0;i--) {
            dp[i][1] = max(dp[i][1], a[i].second * a[i].first + dp[i+1][0]);
            dp[i][1] = max(dp[i][1], dp[i+1][1]);

            dp[i][0] = max(dp[i][0], dp[i+1][1]);
            if((i == 0) || (a[i].first != a[i-1].first + 1)) {
                dp[i][0] = max(dp[i][0], a[i].second * a[i].first + dp[i+1][0]);
            }
        }

        return dp[0][1];
    }
};