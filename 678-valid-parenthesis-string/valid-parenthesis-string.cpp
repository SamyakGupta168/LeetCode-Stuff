class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        for(auto x : s) {
            if(x == '(') {
                mini++;
                maxi++;
            } else if(x == ')') {
                mini--;
                maxi--;
            } else {
                mini--;
                maxi++;
            }
            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }
        return mini == 0;
    }
};