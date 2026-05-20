class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> c(n);
        vector<int> t1(n+1, 0), t2(n+1, 0);
        for(int i=0;i<n;i++) {
            t1[a[i]] = 1;   
            t2[b[i]] = 1;
            for(int j=0;j<=i;j++) {
                if(t2[a[j]]) c[i]++;
            }
        }

        return c;
    }
};