class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(a[i] <= b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }

        while(i < n) ans.push_back(a[i++]);
        while(j < m) ans.push_back(b[j++]);
        a = ans;
    }
};