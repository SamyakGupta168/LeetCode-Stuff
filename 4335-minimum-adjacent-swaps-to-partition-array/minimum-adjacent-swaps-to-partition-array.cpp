class Solution {
public:
    long long mod = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();    
        long long ans = 0;
        int p = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] < a) {
                ans += i - p;
                ans %= mod;
                p++;
            }
        }

        int ex = 0;
        p = n-1;
        for(int i=n-1;i>=0;i--) {
            if(nums[i] < a) ex++;
            else if(nums[i] > b) {
                ans += p - i - ex;
                ans %= mod;
                p--;
            }
        }

        return (int)ans;
    }
};