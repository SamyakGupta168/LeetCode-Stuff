class Solution {
public:
    using ll = long long;
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++) {
            adj[parent[i]].push_back(i);
        }

        int h = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    q.push(it);
                }
            }
            h++;
        }

        ll ans = 0;
        int d = 1;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                int node = q.front();
                q.pop();
                ans += 1LL * nums[node] * (h - d + 1);
                for(auto it : adj[node]) q.push(it);
            }
            d++;
        }

        return ans;
    }
};