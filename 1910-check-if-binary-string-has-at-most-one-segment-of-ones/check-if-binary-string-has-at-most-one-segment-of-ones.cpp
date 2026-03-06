class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        bool flag=false;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='1') flag=true;
            else {
                if(flag) {
                    cnt++;
                    flag = !flag;
                }
            }
        }
        if(flag) cnt++;
        return (cnt<2);
    }
};