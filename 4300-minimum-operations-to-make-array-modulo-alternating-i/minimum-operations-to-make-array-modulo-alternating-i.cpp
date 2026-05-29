class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> v1(k), v2(k);
        for(int i=0;i<n;i++) {
            nums[i] %= k;
        }

        for(int x=0;x<k;x++) {
            int opr = 0;
            for(int i=0;i<n;i+=2) {
                opr += min(abs(x - nums[i]), k - abs(x - nums[i]));
            }
            v1[x] = opr;
        }

        for(int x=0;x<k;x++) {
            int opr = 0;
            for(int i=1;i<n;i+=2) {
                opr += min(abs(x - nums[i]), k - abs(x - nums[i]));
            }
            v2[x] = opr;
        }

        int ans = INT_MAX;
        for(int x=0;x<k;x++) {
            for(int y=0;y<k;y++) {
                if(x != y) ans = min(ans, v1[x] + v2[y]);
            }
        }

        return ans;
    }
};