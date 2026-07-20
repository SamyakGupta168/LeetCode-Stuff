class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int b1 = start[0] % 2 == start[1] % 2;
        int b2 = target[0] % 2 == target[1] % 2;
        return b1 == b2;
    }
};