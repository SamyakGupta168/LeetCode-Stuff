class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int s = 0, p = 1;
        while(temp > 0) {
            int d = temp % 10;
            s += d;
            p *= d;
            temp /= 10;
        }

        return (n % (s + p) == 0);
    }
};