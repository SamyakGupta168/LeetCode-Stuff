class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = (1<<20) - 1;
        for(int bit=19;bit>=0;bit--) {
            int wans = ans^(1<<bit);
            bool pos = true;
            for(auto &row : grid) {
                bool sub = false;
                for(auto x : row) {
                    if((wans | x)==wans) sub=true;
                }
                if(!sub) pos=false;
            }
            if(!pos) continue;
            ans = wans;
        }
        return ans;
    }
};