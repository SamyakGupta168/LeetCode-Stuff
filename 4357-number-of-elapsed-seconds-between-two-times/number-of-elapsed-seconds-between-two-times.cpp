class Solution {
public:
    int secondsBetweenTimes(string st, string end) {
        int h1 = (st[0]-'0')*10 + (st[1]-'0');
        int h2 = (end[0]-'0')*10 + (end[1]-'0');
        int m1 = (st[3]-'0')*10 + (st[4]-'0');
        int m2 = (end[3]-'0')*10 + (end[4]-'0');
        int s1 = (st[6]-'0')*10 + (st[7]-'0');
        int s2 = (end[6]-'0')*10 + (end[7]-'0');

        return 60*60*(h2 - h1) + 60*(m2 - m1) + (s2 - s1);
    }
};