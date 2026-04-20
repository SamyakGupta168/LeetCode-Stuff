class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = -1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(colors[i]!=colors[j]) maxi = max(maxi, abs(i-j));
            }
        }

        return maxi;
    }
};