class Solution {
public:

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({arr[i], i});
        sort(v.begin(), v.end());

        for(int i=0;i<n;i++) {
            int val = v[i].first;
            int idx = v[i].second;
            int maxi = 1;
            for(int j=idx-1;j>=max(idx-d, 0);j--) {
                if(arr[j] >= val) break;
                maxi = max(maxi, 1 + dp[j]);
            }

            for(int j=idx+1;j<=min(idx+d, n-1);j++) {
                if(arr[j] >= val) break;
                maxi = max(maxi, 1 + dp[j]);
            }
            dp[idx] = maxi;
        }

        return *max_element(dp.begin(), dp.end());
    }
};