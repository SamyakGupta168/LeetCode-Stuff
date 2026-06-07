class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int cnt = 0;
        for(int x = max(1, n-k); x <= n+k; x++) {
            if((n&x) == 0) cnt+=x;
        }
        return cnt;
    }
};