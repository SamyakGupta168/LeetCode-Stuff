class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string> st;
        for(auto &s : wordList) st.insert(s);

        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while(!q.empty()) {
            int steps = q.front().first;
            string word = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(auto &ch : word) {
                char org = ch;
                for(char c='a';c<='z';c++) {
                    ch = c;
                    if(st.count(word)) {
                        q.push({steps + 1, word});
                        st.erase(word);
                    }
                }
                ch = org;
            }
        }

        return 0;
    }
};