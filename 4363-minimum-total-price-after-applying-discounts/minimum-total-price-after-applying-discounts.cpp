class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& dis) {
        sort(prices.rbegin(), prices.rend());
        sort(dis.rbegin(), dis.rend());
        int i = 0, j = 0;
        int n = prices.size(), m = dis.size();
        double ans = 0;
        while(i < n && j < m) {
            double p = prices[i], d = dis[j];
            ans += ((p * (100.00000 - d)) / 100.00000) * 1.00000;
            i++, j++;
        }

        while(i < n) ans += prices[i++];
        return ans;
    }
};