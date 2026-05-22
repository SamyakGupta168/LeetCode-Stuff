class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](auto &t1, auto &t2) -> bool {
            return (t1[1]-t1[0]) > (t2[1]-t2[0]);
        });

        auto check = [&](int x) -> bool {
            for(auto &v : tasks) {
                if(x >= v[1]) {
                    x -= v[0];
                } else {
                    return false;
                }
            }
            return true;
        };

        int low = 1, high = 1e9;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(check(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};