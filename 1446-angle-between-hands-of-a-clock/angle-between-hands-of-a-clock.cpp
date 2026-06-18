class Solution {
public:
    double angleClock(int hr, int mins) {
        double hangle = (30.0*hr) + (mins/2.0);
        double minangle = mins*6.0;
        double res = abs(hangle - minangle);
        return min(res, 360.0 - res); 
    }
};