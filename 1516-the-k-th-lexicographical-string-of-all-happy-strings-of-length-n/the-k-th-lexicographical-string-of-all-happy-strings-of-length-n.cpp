class Solution {
public:
    bool check(string s) {
        if(s.size()==0 || s.size()==1) return true;
        for(int i=0;i<s.size();i++) {
            if(s[i]==s[i+1]) return false;
        }
        return true;
    }

    void solve(int idx, int n, string &curr, vector<string>&ans) {
        if(idx>n) return;
        if(idx==n) {
            ans.push_back(curr);
            return;
        }

        for(char ch='a';ch<='c';ch++) {
            curr+=ch;
            if(check(curr)) {
                solve(idx+1, n, curr, ans);
            }
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr = "";
        solve(0, n, curr, ans);
        if(ans.size() < k) return "";
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};