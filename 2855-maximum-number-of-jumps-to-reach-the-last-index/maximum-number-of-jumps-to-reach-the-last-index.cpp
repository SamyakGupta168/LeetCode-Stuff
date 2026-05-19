class Solution {
public:
    using ll = long long;

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // Once an index is visited we can't go back, we can only go forward
        vector<ll> jump(n, -1);
        priority_queue<pair<ll,ll>> pq;
        pq.push({0, 0}); // {steps, idx}
        jump[0] = 0;
        while(!pq.empty()) {
            int steps = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            for(int i=idx+1;i<n;i++) {
                ll diff = (ll)nums[i]-nums[idx];
                if(diff<=target && diff>=(-target)) {
                    if(jump[i] < jump[idx] + 1) {
                        jump[i] = jump[idx]+1;
                        pq.push({jump[i], i});
                    }
                }
            }
        }

        return (jump[n-1] != -1) ? jump[n-1] : -1;
    }
};