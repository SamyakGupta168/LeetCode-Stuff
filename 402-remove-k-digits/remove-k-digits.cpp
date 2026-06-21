class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) return "0";
        stack<char> st;
        string ans;

        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top() > num[i] && k) {
                st.pop(), k--;
            }
            st.push(num[i]);
        }

        while(k) {
            st.pop();
            k--;
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        int idx = -1;
        for(int i=0;i<ans.size();i++) {
            if(ans[i] == '0') idx = i;
            else break;
        }

        if(idx == ans.size() - 1) ans = "0";
        else if(idx != -1) ans = ans.substr(idx+1);

        return ans;
    }
};