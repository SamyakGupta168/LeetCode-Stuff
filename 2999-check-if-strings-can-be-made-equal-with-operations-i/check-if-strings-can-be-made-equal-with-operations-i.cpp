class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        multiset<char> ms1, ms2;
        bool flag = true;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                ms1.insert(s1[i]);
                ms2.insert(s2[i]);
            }
        }

        flag &= (ms1==ms2);
        if(!flag) return false;
        ms1.clear(); ms2.clear();

        for(int i=0;i<n;i++) {
            if(i&1) {
                ms1.insert(s1[i]);
                ms2.insert(s2[i]);
            }
        }

        flag &= (ms1==ms2);
        return flag;
    }
};