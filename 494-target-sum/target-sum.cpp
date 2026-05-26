class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        vector<int> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = 1;
        if(arr[0] <= sum) prev[arr[0]] = 1;
        if(arr[0] == 0 && arr[0] <= sum) prev[arr[0]] = 2;
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<=sum;j++) {
                int notTake = prev[j];
                int take = 0;
                if(j >= arr[i]) {
                    take = prev[j - arr[i]];
                }
                curr[j] = notTake + take;
            }
            prev = curr;
        }
        
        int cnt = 0;
        for(int i=0;i<=sum;i++) {
            if(sum - 2*i == diff) cnt += prev[i];
        }
        
        return cnt;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};