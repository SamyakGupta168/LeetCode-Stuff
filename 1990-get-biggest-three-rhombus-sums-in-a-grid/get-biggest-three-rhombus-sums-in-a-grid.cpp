class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m =grid[0].size();
        set<int> st;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int l=0; ;l++) {
                    if(i+2*l>=n || j+l>=m || j-l<0) break;
                    int sum = 0;
                    if(l==0) sum = grid[i][j];
                    else {
                        // Iterate for all 4 edges
                        for(int k=0;k<l;k++) {
                            sum+=grid[i+k][j+k];
                        }
                        for(int k=0;k<l;k++) {
                            sum+=grid[i+l+k][j+l-k];
                        }
                        for(int k=0;k<l;k++) {
                            sum+=grid[i+2*l-k][j-k];
                        }
                        for(int k=0;k<l;k++) {
                            sum+=grid[i+l-k][j-l+k];
                        }
                    }

                    st.insert(sum);
                    if(st.size() > 3) st.erase(st.begin());
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};