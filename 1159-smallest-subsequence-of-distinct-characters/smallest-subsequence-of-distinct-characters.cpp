class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> cnt(26);
        for(auto ch : s) cnt[ch - 'a']++;
        vector<int> hash(26, 0);
        stack<char> st;
        st.push(s[0]);
        hash[s[0] - 'a']++;
        cnt[s[0] - 'a']--;
        for(int i=1;i<n;i++) {
            cnt[s[i] - 'a']--;
            if(hash[s[i] - 'a']) continue;
            while(!st.empty() && st.top() > s[i] && cnt[st.top() - 'a'] > 0) {
                hash[st.top() - 'a']--;
                st.pop();
            }
            st.push(s[i]);
            hash[st.top() - 'a']++;
        }

        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};