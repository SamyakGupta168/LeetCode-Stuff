class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int i = n-2;i>=0;i--) {
            int minJump = 1e9;
            for(int jumpIdx=i+1;jumpIdx<=min(i+arr[i], n-1);jumpIdx++) {
                minJump = min(minJump, 1 + dp[jumpIdx]);
            }
            dp[i] = minJump;
        }
        
        return (dp[0] != 1e9 ? dp[0] : -1);
    }
};