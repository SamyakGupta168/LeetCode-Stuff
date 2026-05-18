class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // cout<<n<<'\n';
        unordered_map<int, set<int>> index;
        for(int i=0;i<n;i++) {
            index[arr[i]].insert(i);
        }

        vector<int> vis(n, 0);
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()) {
            int pos = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(pos == n-1) return steps;

            if(pos-1 >= 0 && !vis[pos-1]) {
                vis[pos-1] = 1;
                q.push({pos-1, steps+1});
            }

            if(pos+1 < n && !vis[pos+1]) {
                vis[pos+1] = 1;
                q.push({pos+1, steps+1});
            }

            vector<int> used;
            for(auto idx : index[arr[pos]]) {
                vis[idx] = 1;
                q.push({idx, steps+1});
                used.push_back(idx);
            }

            index.erase(arr[pos]);
        }

        return -1;
    }
};