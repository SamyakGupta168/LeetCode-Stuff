class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto x : nums) mp[x]++;

        vector<pair<int,int>> a;
        for(auto p : mp) {
            a.push_back({p.first, p.second});
        }

        int n = a.size();
        vector<int> next(2, 0), curr(2, 0);

        for(int i=n-1;i>=0;i--) {
            curr[1] = max(curr[1], a[i].second * a[i].first + next[0]);
            curr[1] = max(curr[1], next[1]);

            curr[0] = max(curr[0], next[1]);
            if((i == 0) || (a[i].first != a[i-1].first + 1)) {
                curr[0] = max(curr[0], a[i].second * a[i].first + next[0]);
            }
            next = curr;
        }

        return next[1];
    }
};