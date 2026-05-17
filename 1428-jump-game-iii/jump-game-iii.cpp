class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;
        vis[start] = 1;
        q.push(start);
        while(!q.empty()) {
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0) return true;

            int idx1 = idx - arr[idx];
            if(idx1 >= 0 && idx1 < n) {
                if(!vis[idx1]) {
                    vis[idx1] = 1;
                    q.push(idx1);
                }
            }

            int idx2 = idx + arr[idx];
            if(idx2 >= 0 && idx2 < n) {
                if(!vis[idx2]) {
                    vis[idx2] = 1;
                    q.push(idx2);
                }
            }
        }

        return false;
    }
};