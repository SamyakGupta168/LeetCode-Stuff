class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](auto &t1, auto &t2) -> bool {
            return (t1[1]-t1[0]) < (t2[1]-t2[0]);
        });

        int ans = 0;
        for(auto &v : tasks) {
            int task =v[0], barrier = v[1];
            ans = max(ans+task, barrier);
        }

        return ans;
    }
};