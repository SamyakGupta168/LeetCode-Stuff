class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        map<int,int> rank;
        int rk = 1;
        for(auto x : st) rank[x] = rk++;

        vector<int> ans;
        for(auto x : arr) {
            ans.push_back(rank[x]);
        }

        return ans;
    }
};