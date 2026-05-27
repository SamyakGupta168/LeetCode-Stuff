class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        map<char, int> mp;
        for(int i=0;i<word.size();i++) {
            if(word[i] >='a' && word[i] <= 'z') mp[word[i]] = i;
            else if(!mp.count(word[i])) mp[word[i]] = i;
        }

        for(auto p : mp) {
            char ch = p.first;
            if(ch >= 'a' && ch <= 'z') {
                if(mp.count(toupper(ch)) && mp[ch] < mp[toupper(ch)]) cnt++;
            }
        }

        return cnt;
    }
};