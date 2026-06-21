class Solution {
public:
    bool isValid(long long n, long long x) {
        long first = -1, last = -1;
        first = n % 10;
        while(n > 0) {
            last = n % 10;
            n /= 10;
        }
        return (last == first) && (last == x);
    }
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            long long sum = 0;
            for(int j=i;j<n;j++) {
                sum += (long long)nums[j];
                if(isValid(sum, x)) cnt++;
            }
        }

        return cnt;
    }
};