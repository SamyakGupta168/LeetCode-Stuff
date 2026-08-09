class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ps(n, vector<int>(m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ps[i][j] = mat[i][j];
                if(i-1 >= 0) ps[i][j] += ps[i-1][j];
                if(j-1 >= 0) ps[i][j] += ps[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) ps[i][j] -= ps[i-1][j-1];
            }
        }

        auto check = [&] (int k) ->bool {
            int minr = INT_MAX, maxr = INT_MIN;
            int minc = INT_MAX, maxc = INT_MIN;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    int nr = i + k - 1, nc = j + k - 1;
                    if(nr >= n || nc >= m) continue;
                    int sum = ps[nr][nc];
                    if(j-1 >= 0) sum -= ps[nr][j-1];
                    if(i-1 >= 0) sum -= ps[i-1][nc];
                    if(i-1 >= 0 && j-1 >= 0) sum += ps[i-1][j-1];
                    if(sum == k*k) {
                        minr = min(minr, i);
                        maxr = max(maxr, i);
                        minc = min(minc, j);
                        maxc = max(maxc, j);
                    }
                }   
            }

            if(minr != INT_MAX && maxr != INT_MIN && maxr - minr >= k) return true; 
            if(minc != INT_MAX && maxc != INT_MIN && maxc - minc >= k) return true;
            return false;
        };

        int low = 1, high = min(n, m);
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (ans != -1) ? ans*ans : 0;
    }
};