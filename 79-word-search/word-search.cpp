class Solution {
public:
    using ll = long long;

    ll dx[4] = {1, -1, 0, 0};
    ll dy[4] = {0, 0, 1, -1};

    bool dfs(ll r, ll c, string &s, ll sz, ll idx, ll n, ll m, vector<vector<char>>&grid) {
        if(idx == sz) return true;
        if(r < 0 || c < 0 || r >= n || c >= m) return false;
        if(s[idx] != grid[r][c]) return false;
        char ch = s[idx];
        grid[r][c] = '*';
        bool flag = false;
        for(ll i=0;i<4;i++) {
            ll nr = r + dx[i], nc = c + dy[i];
            if(dfs(nr, nc, s, sz, idx+1, n, m, grid)) {
                flag = true;
                break;
            }
        }
        grid[r][c] = ch;
        return flag;
    }

    bool exist(vector<vector<char>>& grid, string s) {
        ll n = grid.size(), m = grid[0].size();
        ll sz = s.size();
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                if(dfs(i, j, s, sz, 0, n, m, grid)) {
                    return true;
                }
            }
        }

        return false;
    }
};