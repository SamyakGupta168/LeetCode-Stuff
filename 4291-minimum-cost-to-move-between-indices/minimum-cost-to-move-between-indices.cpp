class Solution {
public:
    using ll = long long;

    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> close(n);
        for(int i=0;i<n;i++) {
            if(i==0) close[i] = i+1;
            else if(i==n-1) close[i] = i-1;
            else {
                if(abs(nums[i]-nums[i-1]) > abs(nums[i]-nums[i+1])) close[i] = i+1;
                else close[i] = i-1;
            }
        }

        vector<ll> f(n), b(n);
        for(int i=1;i<n;i++) {
            if(close[i-1]==i) f[i] = f[i-1]+1;
            else f[i] = f[i-1] + nums[i] - nums[i-1];
        }

        for(int i=n-2;i>=0;i--) {
            if(close[i+1]==i) b[i] = b[i+1]+1;
            else b[i] = b[i+1] + nums[i+1] - nums[i];
        }

        vector<int> ans;
        for(auto &q : queries) {
            int l = q[0], r = q[1];
            if(l<r) ans.push_back(f[r] - f[l]);
            else ans.push_back(b[r] - b[l]);
        }

        return ans;
    }
};