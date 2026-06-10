class Solution {
public:
    int f(int i, vector<int>&arr, int k, vector<int>&dp) {
        int n = arr.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = 0, maxVal = 0;
        for(int j=i;j<=min(i+k-1, n-1);j++) {
            maxVal = max(maxVal, arr[j]);
            maxi = max(maxi, (j - i + 1) * maxVal + f(j+1, arr, k, dp));
        }

        return dp[i] = maxi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k, dp);
    }
};