class Solution {
public:
    vector<int> printCircuit(vector<vector<pair<int,int>>> &adj) {
        int n = adj.size() - 1;

        if (n == 0)
            return {};

        vector<int> currPath;
        currPath.push_back(1);

        vector<int> circuit;

        while (currPath.size() > 0) {
            int currNode = currPath[currPath.size() - 1];

            if (adj[currNode].size() > 0) {
                int nextNode = adj[currNode].back().first;
                adj[currNode].pop_back();

                currPath.push_back(nextNode);
            } else {
                circuit.push_back(currPath.back());
                currPath.pop_back();
            }
        }

        reverse(circuit.begin(), circuit.end());

        return circuit;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        map<int, map<int,int>> mp;
        for (auto& x : roads) {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            mp[u][v] = w;
            mp[v][u] = w;
        }

        vector<int> cycle = printCircuit(adj);
        int minScore = INT_MAX;
        for(int i=1;i<cycle.size();i++) {
            minScore = min(minScore, mp[cycle[i-1]][cycle[i]]);
        }

        return minScore;
    }
};