class Solution {
public:
    int product(int n) {
        int p = 1;
        if(n == 0) return 0;
        while(n > 0) {
            p *= (n % 10);
            n /= 10;
        }
        return p;
    }

    int smallestNumber(int n, int t) {
        for(int x=n;x<n+10;x++) {
            if(product(x) % t == 0) return x;
        }
        return -1;
    }
};