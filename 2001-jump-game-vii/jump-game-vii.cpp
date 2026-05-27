class Solution {
public:
    bool canReach(string s, int mnj, int mxj) {
        int n = s.size();
        vector<int> t(n, 0);
        int cnt = 0;
        t[0] = 1;
        for(int j=1;j<n;j++) {
            if(j - mnj >= 0) {
                cnt += t[j - mnj];
            }
            if(j - mxj - 1 >= 0) {
                cnt -= t[j - mxj - 1];
            }
            if(cnt > 0 && s[j] == '0') t[j] = 1;
        }

        return t[n-1] > 0;
    }
};