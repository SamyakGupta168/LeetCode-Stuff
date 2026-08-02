class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& sft) {
        int n = sft.size();
        vector<int> ans(n);
        int m = tasks.size();
        vector<long long> pref(m);
        pref[0] = tasks[0];
        for(int i=1;i<m;i++) pref[i] += pref[i-1] + tasks[i];

        long long prev = 0;
        for(int j=0;j<n;j++) {
            long long val = prev + sft[j];
            int idx = lower_bound(pref.begin(), pref.end(), val) - pref.begin();
            if(idx == m) {
                prev = 0;
                continue;
            }
            if(pref[idx] == val) {
                ans[j] = m - idx - 1;
                if(idx == m-1) {
                    prev = 0;
                    continue;
                }
            } else {
                ans[j] = m - idx;
            }
            prev += sft[j];
        }

        return ans;
    }
};