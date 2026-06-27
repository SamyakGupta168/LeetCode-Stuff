class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()) {
            vector<int> v = q.front();
            int node = v.back();
            q.pop();


            if(node == n-1) {
                ans.push_back(v);
                continue;
            }

            for(auto it : graph[node]) {
                auto temp = v;
                temp.push_back(it);
                q.push(temp);
            }
        }

        return ans;
    }
};