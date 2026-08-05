class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int> mp;
        int maxLen = 0;
        int l = 0, r = 0;
        while(r < n) {
            mp[fruits[r]]++;
            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(!mp[fruits[l]]) mp.erase(fruits[l]);
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};