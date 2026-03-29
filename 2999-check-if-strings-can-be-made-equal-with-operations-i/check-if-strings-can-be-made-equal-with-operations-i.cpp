class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> idx = {0, 1, 2, 3};

        do{
            bool flag = true;
            for(int i=0;i<4;i++) {
                if(s2[i]!=s1[idx[i]]) {
                    flag = false;
                    break;
                }
                if(abs(i-idx[i])!=0 && abs(i-idx[i])!=2) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }while(next_permutation(idx.begin(), idx.end()));

        return false;
    }
};