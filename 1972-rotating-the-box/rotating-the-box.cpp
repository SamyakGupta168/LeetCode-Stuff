class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        map<pair<int,int>, int> mp;
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=0;j<m;j++) {
                if(boxGrid[i][j]=='#') cnt++;
                else if(boxGrid[i][j]=='*') {
                    mp[make_pair(i, j)] = cnt;
                    cnt = 0;
                }
            }
            mp[make_pair(i, m)] = cnt;
        }

        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for(auto p : mp) {
            int r = p.first.first, c = p.first.second;
            int cnt = p.second;
            int nr = c, nc = n - r - 1;
            if(nr != m) ans[nr][nc] = '*';
            while(cnt>0) {
                ans[nr-1][nc] = '#';
                cnt--, nr--;
            }
        }

        return ans;
    }
};