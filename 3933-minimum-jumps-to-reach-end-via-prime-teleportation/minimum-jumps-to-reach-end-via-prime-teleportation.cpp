class Solution {
public:
    static vector<int> spf;

    static void SPF() {
        static bool done = false;
        if(done) return;
        done = true;

        for (int i = 0; i <= 1e6; i++) spf[i] = i;
        spf[0] = -1, spf[1] = -1;

        for (int i = 2; i * i <= 1e6; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= 1e6; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        SPF();
        int n = nums.size();
        vector<vector<int>> fact(n);
        for(int i=0;i<n;i++) {
            int temp = nums[i];
            while(temp > 1) {
                int p = spf[temp];
                fact[i].push_back(p);
                while(temp%p==0) temp/=p;
            }
        }

        unordered_map<int, vector<int>> edges;
        for(int i=0;i<n;i++) {
            for(int p : fact[i]) {
                edges[p].push_back(i);
            }
        }

        vector<int> vis(n, 0);
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()) {
            int idx = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(idx == n-1) return steps;

            if(idx > 0 && !vis[idx-1]) {
                vis[idx-1] = 1;
                q.push({idx-1, steps+1});
            }
            if(idx < n-1 && !vis[idx+1]) {
                vis[idx+1] = 1;
                q.push({idx+1, steps+1});
            }

            if(spf[nums[idx]] != nums[idx]) continue;

            int p = nums[idx];

            if(edges.count(p)) {
                for(int j : edges[p]) {
                    if(!vis[j]) {
                        vis[j] = 1;
                        q.push({j, steps+1});
                    }
                }
                edges.erase(p);
            }

        }

        return -1;
    }
};

vector<int> Solution::spf(1e6 + 1);