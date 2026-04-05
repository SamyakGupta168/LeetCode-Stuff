class Solution {
public:
    bool judgeCircle(string moves) {
        int r = 0, c = 0;
        for(int i=0;i<moves.size();i++) {
            if(moves[i] == 'L') c--;
            else if(moves[i] == 'R') c++;
            else if(moves[i] == 'U') r--;
            else r++;
        }

        return (r==0 && c==0) ? true : false;
    }
};