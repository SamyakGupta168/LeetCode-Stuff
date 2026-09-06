class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            char c = s[0];
            string temp = s.substr(1);
            s = temp;
            s += c;
            int sc = 0;
            for(int i=1;i<n;i++) {
                if(s[i] == s[i-1]) sc++;
            }
            cnt += (sc == k);
        }

        return cnt;
    }
};