class Solution {
public:
    int rev(int n) {
        int val = 0;
        while(n > 0) {
            int d = n%10;
            val = val*10 + d;
            n/=10;
        }
        
        return val;
    }

    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};