class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        unordered_map<int, int> mp; // {prefix, length}
        for(int i=0;i<n;i++) {
            int num = arr1[i];
            int len = 0;
            while(num > 0) {
                len++;
                num/=10;
            }

            num = arr1[i];
            while(num > 0) {
                mp[num] = len;
                num/=10;
                len--;
            }
        }

        int maxLen = 0;
        for(int i=0;i<m;i++) {
            int num = arr2[i];
            while(num > 0) {
                if(mp.count(num)) maxLen = max(maxLen, mp[num]);
                num/=10;
            }
        }

        return maxLen;
    }
};