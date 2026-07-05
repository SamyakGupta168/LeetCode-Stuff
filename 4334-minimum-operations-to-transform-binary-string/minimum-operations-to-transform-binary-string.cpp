class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1 && s1[0] == '1' && s2[0] == '0') return -1;

        int opr = 0;
        for(int i=0;i<n;i++) {
            if(s1[i] =='0' && s2[i] == '1') {
                opr++;
                s1[i] = '1';
            }
        }

        int len = 0;
        for(int i=0;i<n;i++) {
            if(s1[i] == '1' && s2[i] == '0') len++;
            else {
                if(len) {
                    if(len & 1) opr += len / 2 + 2;
                    else opr += len / 2;
                }
                len = 0;
            }
        }
        if(len) {
            if(len & 1) opr += len / 2 + 2;
            else opr += len / 2;
        }

        return opr;
    }
};