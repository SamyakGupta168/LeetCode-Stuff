class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0;
        int maxi = 0;
        for(auto x : gain) {
            height += x;
            maxi = max(maxi, height);
        }

        return maxi;
    }
};