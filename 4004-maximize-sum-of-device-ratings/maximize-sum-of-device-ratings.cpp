class Solution {
public:
    using ll = long long;

    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size(), m = units[0].size();
        if(m == 1) {
            ll sum = 0;
            for(auto &v : units) sum += v[0];
            return sum;
        }

        ll sum = 0, mn1 = LLONG_MAX, mn2 = LLONG_MAX;
        for(int i=0;i<n;i++) {
            sort(units[i].begin(), units[i].end());
            sum += units[i][1];
            mn1 = min(mn1, (ll)units[i][0]);
            mn2 = min(mn2, (ll)units[i][1]);
        }

        return sum + mn1 - mn2;
    }
};