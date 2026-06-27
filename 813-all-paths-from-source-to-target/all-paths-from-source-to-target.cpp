class Solution {
public:
    void dfs(int node, vector<vector<int>>&graph, vector<int>&path, vector<vector<int>>&ans, int n) {
        path.push_back(node);
        if(path.back() == n-1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(auto it : graph[node]) {
            dfs(it, graph, path, ans, n);
        }
        path.pop_back();
    } 

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, graph, path, ans, n);
        return ans;
    }
};