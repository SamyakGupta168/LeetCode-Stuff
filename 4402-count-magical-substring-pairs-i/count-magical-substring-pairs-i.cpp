class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n-1;i++) {
            vector<int> pref(27), suff(27);
            set<char> st;
            for(int j=i;j>=0;j--) {
                st.insert(s[j]);
                pref[(int)st.size()]++;
            }
            st.clear();
            for(int j=i+1;j<n;j++) {
                st.insert(s[j]);
                suff[(int)st.size()]++;
            }
            for(int j=0;j<=26;j++) ans += (pref[j] * suff[j]);
        }

        return ans;
    }
};