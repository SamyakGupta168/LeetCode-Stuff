class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(auto x : nums) {
            int c = 0;
            string res = "";
            while(x > 1) {
                if(c == 25) break;
                if(x&1) res += char('a' + c);
                c++;
                x/=2;
            }
            while(x--) res += char('a' + c);
            reverse(res.begin(), res.end());
            ans.push_back(res);
        }
        return ans;
    }
};