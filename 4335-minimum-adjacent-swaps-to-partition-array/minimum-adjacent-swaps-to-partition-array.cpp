class Solution {
public:
    long long mod = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> ind1;
        int ca = 0, cb = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] < a) {
                ca++;
            }
            if(nums[i] > b) {
                cb++;
                ind1.push_back(i);
            }
        }

        long long ans = 0, idx = n-1;
        while(cb > 0) {
            ans += idx - ind1.back();
            ans %= mod;
            ind1.pop_back();
            idx--, cb--;
        }

        vector<int> temp;
        for(auto x : nums) {
            if(x <= b) temp.push_back(x);
        }

        for(auto x : nums) {
            if(x > b) temp.push_back(x); 
        }

        vector<int> ind2;
        for(int i=n-1;i>=0;i--) {
            if(temp[i] < a) ind2.push_back(i);
        }

        idx = 0;
        while(ca > 0) {
            ans += ind2.back() - idx;
            ans %= mod;
            ind2.pop_back();
            idx++, ca--;
        }

        return (int)ans;
    }
};