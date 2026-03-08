class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n==1) return 0;
        if(n==2) {
            if(s[0]>s[1]) return -1;
            return 0; 
        }
        string temp = s;
        sort(temp.begin(), temp.end());
        if(temp==s) return 0;
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        char hi = temp[n-1], lw = temp[0];
        if(s[0]==lw || s[n-1]==hi) return 1;
        if(s[0]==hi && s[n-1]==lw) {
            if(mp[hi]==1 && mp[lw]==1) return 3;
        }
        return 2;
    }
};