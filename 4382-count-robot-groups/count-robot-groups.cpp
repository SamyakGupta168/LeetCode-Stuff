class Solution {
public:
    int countGroups(vector<int>& pos, vector<int>& sp, int d) {
        int n = pos.size();
        vector<int> np, ns;
        np.push_back(pos.back());
        ns.push_back(sp.back());
        for(int i=n-2;i>=0;i--) {
            if(pos[i+1] - pos[i] > d) {
                np.push_back(pos[i]);
                ns.push_back(sp[i]);
            }
        }

        reverse(np.begin(), np.end());
        reverse(ns.begin(), ns.end());

        int cnt = 1, cur = ns.back();
        int sz = ns.size();
        for(int i=sz-2;i>=0;i--) {
            if(ns[i] <= cur) {
                cnt++;
                cur = ns[i];
            }
        }

        return cnt;
    }
};