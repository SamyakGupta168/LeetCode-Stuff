class Solution {
public:
    int elevatorRequests(int n, vector<int>& req) {
        req.insert(req.begin(), 0);
        int ans = 0;
        for(int i=1;i<req.size();i++) ans += abs(req[i] - req[i-1]);
        return ans; 
    }
};