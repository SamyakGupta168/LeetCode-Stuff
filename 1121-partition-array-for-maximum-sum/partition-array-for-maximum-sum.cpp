class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1;i>=0;i--) {
            int maxVal = 0;
            for(int j=i;j<=min(i+k-1, n-1);j++) {
                maxVal = max(maxVal, arr[j]);
                dp[i] = max(dp[i], (j - i + 1) * maxVal + dp[j+1]);
            }
        }

        return dp[0];
    }
};