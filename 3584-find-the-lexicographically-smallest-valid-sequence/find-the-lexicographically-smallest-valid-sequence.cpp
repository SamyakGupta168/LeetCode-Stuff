class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> rightMatchLen(n, 0);
        int j = m-1;
        for(int i=n-1;i>=0;i--) {
            if(j >= 0) {
                if(word1[i] == word2[j]) j--;
            }
            rightMatchLen[i] = m - j - 1;
        }

        vector<int> seq;
        int i = 0;
        j = 0;
        bool changePower = true;
        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                seq.push_back(i);
                i++, j++;
                continue;
            }

            if(i+1 < n && changePower && rightMatchLen[i+1] >= m - j - 1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }
            i++;
        }

        if(j == m) return seq;
        return {};
    }
};