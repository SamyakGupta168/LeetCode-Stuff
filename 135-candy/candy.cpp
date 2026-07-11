class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> left(n, 1);
        for(int i=1;i<n;i++) {
            if(rat[i] > rat[i-1]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 1;
            }
        }

        int cnt = max(1, left[n-1]), right = 1, cur = 1;
        for(int i=n-2;i>=0;i--) {
            if(rat[i] > rat[i+1]) {
                cur = right + 1;
            } else {
                cur = 1;
            }
            cnt += max(left[i], cur);
            right = cur;
        }

        return cnt;
    }
};