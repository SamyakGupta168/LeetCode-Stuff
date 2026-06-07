class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        if(arr[0] == 0) return -1;
        int jump = 0, currReach = 0, maxReach = 0;
        for(int i=0;i<n;i++) {
            maxReach = max(maxReach, i + arr[i]);
            if(maxReach >= n-1) {
                return jump + 1;
            }
            if(i == currReach) {
                if(maxReach == i) {
                    return -1;
                }
                jump++;
                currReach = maxReach;
            }
        }
        
        return -1;
    }
};