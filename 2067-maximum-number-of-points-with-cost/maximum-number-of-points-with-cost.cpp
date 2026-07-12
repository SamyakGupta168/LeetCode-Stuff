class Solution {
public:
    using ll = long long;
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<ll> prev(m, 0), cur(m, 0);
        for(int j=0;j<m;j++) {
            prev[j] = points[0][j];
        }

        vector<ll> left(m, prev[0]), right(m, prev[m-1] - m + 1);
        for(int j=1;j<m;j++) left[j] = max(left[j-1], prev[j] + j);
        for(int j=m-2;j>=0;j--) right[j] = max(right[j+1], prev[j] - j);

        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                cur[j] = points[i][j] + max(left[j] - j, right[j] + j);
            }

            left[0] = cur[0];
            right[m-1] = cur[m-1] - m + 1;
            for(int j=1;j<m;j++) {
                left[j] = 0;
                left[j] = max(left[j-1], cur[j] + j);
            }
            for(int j=m-2;j>=0;j--) {
                right[j] = 0;
                right[j] = max(right[j+1], cur[j] - j);
            }
            prev = cur;
        }

        return *max_element(prev.begin(), prev.end());
    }
};