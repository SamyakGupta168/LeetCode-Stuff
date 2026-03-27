class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> mat1 = mat;
        vector<int> temp(m);
        for(int i=0;i<n;i++) {
            if(i&1) {
                for(int j=0;j<m;j++) temp[(j+k)%m] = mat[i][j];
            } else {
                for(int j=0;j<m;j++) temp[(j%m - k%m + m)%m] = mat[i][j];
            }
            for(int j=0;j<m;j++) mat[i][j] = temp[j];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat1[i][j]!=mat[i][j]) return false;
            }
        }

        return true;
    }
};