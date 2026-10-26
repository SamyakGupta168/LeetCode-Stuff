class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        vector<int> good(n+1, 0), cnt(n+1, 0);
        int len = 1;
        while(len*(len+1)/2 <= n) {
            good[len*(len+1)/2] = 1;
            cnt[len*(len+1)/2] = len;
            len++;
        }

        int ans = 0;
        vector<int> rank(100001, 0), freq(50001, 0);
        vector<int> dis;
        for(int i=0;i<n;i++) {
            dis.clear();
            for(int j=i;j<n;j++) {
                if(!rank[nums[j]]) {
                    int rk = dis.size();
                    rank[nums[j]] = rk + 1;
                    dis.push_back(nums[j]);
                }
                freq[rank[nums[j]]]++;
                int u = dis.size();
                if(i + u*(u+1)/2 > n) break;
                if(rank[nums[j]] < freq[rank[nums[j]]]) break;
                if(good[j-i+1] && cnt[j-i+1] == (int)dis.size()) ans++;
            }
            int r = 1;
            for(auto x : dis) {
                rank[x] = 0;
                freq[r++] = 0;
            }
        }

        return ans;
    }
};