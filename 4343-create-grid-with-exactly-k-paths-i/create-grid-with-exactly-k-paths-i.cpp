class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        vector<string> ans(n, string(m, '#'));

        if(n == 1 || m == 1) {
            if(k == 1) return vector<string> (n, string(m, '.'));
            else return vector<string> ();
        }

        // n > 1 and m > 1
        if(m >= k) {
            for(int i=0;i<n;i++) ans[i][0] = '.';
            for(int i=0;i<m;i++) ans[n-1][i] = '.';
            if(1 < k) ans[n-2][1] = '.';
            if(2 < k) ans[n-2][2] = '.';
            if(3 < k) ans[n-2][3] = '.';
            return ans;
        }

        if(n >= k) {
            for(int i=0;i<m;i++) ans[0][i] = '.';
            for(int i=0;i<n;i++) ans[i][m-1] = '.';
            if(1 < k) ans[1][m-2] = '.';
            if(2 < k) ans[2][m-2] = '.';
            if(3 < k) ans[3][m-2] = '.';
            return ans;
        }

        // n < k and m < k
        if(k == 4) {
            if(n == 3 && m == 3) {
                vector<string> res(n, string(m, '.'));
                res[0][m-1] = '#';
                res[n-1][0] = '#';
                return res;
            }
        }

        return vector<string> ();
    }
};