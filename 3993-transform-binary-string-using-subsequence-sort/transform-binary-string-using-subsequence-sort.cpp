class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> ans;
        for(auto &tar : strs) {
            int cnt = 0, ext = 0;
            bool flag = true;
            for(int i=0;i<s.size();i++) {
                if(tar[i] == '0' && s[i] == '1') cnt++;
                else if(tar[i] == '1' && s[i] == '0') {
                    if(cnt) cnt--;
                    else if(ext) ext--;
                    else {
                        flag = false;
                        break;
                    }
                } else if(tar[i] == '?' && s[i] == '1') ext++;
                else if(tar[i] == '?' && s[i] == '0') {
                    if(cnt) {
                        cnt--, ext++;
                    }
                }
            }
            if(flag) {
                if(cnt) flag = false;
            } 
            ans.push_back(flag);
        }

        return ans;
    }
};