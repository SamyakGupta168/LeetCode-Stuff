class Solution {
public:
    using ll = long long;
    int minRefuelStops(int tar, int start, vector<vector<int>>& st) {
        st.insert(st.begin(), {0, start});
        int n = st.size();
        // vector<vector<ll>> dp(n, vector<ll>(n, -1));
        vector<ll> prev(n, -1), cur(n, -1);
        prev[0] = start;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(j>0 && prev[j-1] != -1) {
                    if(prev[j-1] + st[i-1][1] >= st[i][0] - st[i-1][0]) {
                        cur[j] = max(cur[j], prev[j-1] + st[i-1][1] - st[i][0] + st[i-1][0]);
                    }
                }

                if(prev[j] != -1 && prev[j] >= st[i][0] - st[i-1][0]) {
                    cur[j] = max(cur[j], prev[j] - st[i][0] + st[i-1][0]);
                }
            }
            prev = cur;
            fill(cur.begin(), cur.end(), -1);
        }

        int ans = INT_MAX;
        for(int j=0;j<n;j++) {
            if(prev[j] != -1) {
                if(st[n-1][0] + prev[j] >= tar) ans = min(ans, j);
                if(st[n-1][0] + prev[j] + st[n-1][1] >= tar) ans = min(ans, j+1);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};