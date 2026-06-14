class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mp;
        for(auto x : bills) {
            if(x == 5) mp[x]++;
            else if(x == 10) {
                if(mp[5] > 0) {
                    mp[5]--;
                    mp[x]++;
                }
                else return false;
            } else {
                if(mp[10] > 0 && mp[5] > 0) {
                    mp[10]--, mp[5]--;
                    mp[x]++;
                } else if(mp[5] >= 3) {
                    mp[5] -= 3;
                    mp[x]++;
                } else return false;
            }
        }

        return true;
    }
};