class Solution {
public:
    int bfs(string &beginWord, string &endWord, vector<string>&wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()) {
            string node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(endWord==node) return level;
            for(int i=0;i<node.size();i++) {
                char orignal = node[i];
                for(char ch='a';ch<='z';ch++) {
                    node[i]=ch;
                    if(st.find(node)!=st.end()) {
                        q.push({node, level+1});
                        st.erase(node);
                    }
                }
                node[i]=orignal;
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord, endWord, wordList);
    }
};