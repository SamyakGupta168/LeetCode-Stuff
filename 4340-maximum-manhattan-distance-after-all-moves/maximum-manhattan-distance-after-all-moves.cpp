class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, cnt = 0;
        for(auto ch : moves) {
            if(ch == 'U') y++;
            else if(ch == 'D') y--;
            else if(ch == 'L') x--;
            else if(ch == 'R') x++;
            else cnt++;
        }

        if(y >= 0) y += cnt;
        else y -= cnt;

        return abs(x) + abs(y);
    }
};