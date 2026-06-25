class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> prev(5, 1), curr(5, 0);
        for(int i=1;i<n;i++) {
            for(int j=0;j<5;j++) {
                curr[j] = 0;
                for(int k=0;k<=j;k++) {
                    curr[j] += prev[k];
                }
            }
            prev = curr;
        }

        return accumulate(prev.begin(), prev.end(), 0);
    }
};