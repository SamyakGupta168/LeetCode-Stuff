class Solution {
public:
    int minBishopMoves(vector<int>& src, vector<int>& tar) {
        int sr = src[0], sc = src[1];
        int tr = tar[0], tc = tar[1];
        int dr = tr - sr, dc = tc - sc;
        if(abs(dc - dr) & 1) return -1;
        if(abs(dc) == abs(dr)) return 1;
        return 2;
    }
};