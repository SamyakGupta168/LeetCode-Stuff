class Solution {
public:
    int f(int idx, int d, vector<int>&dp, vector<int>&arr, int n) {
        if(dp[idx] != -1) return dp[idx];

        int maxi = 1;
        for(int i=idx-1;i>=max(0, idx-d);i--) {
            if(arr[i] >= arr[idx]) break;
            maxi = max(maxi, 1 + f(i, d, dp, arr, n));
        }

        for(int i=idx+1;i<=min(idx+d, n-1);i++) {
            if(arr[i] >= arr[idx]) break;
            maxi = max(maxi, 1 + f(i, d, dp, arr, n));
        }

        return dp[idx] = maxi;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] != -1) ans = max(ans, dp[i]);
            else ans = max(ans, f(i, d, dp, arr, n));
        }

        return ans;
    }
};