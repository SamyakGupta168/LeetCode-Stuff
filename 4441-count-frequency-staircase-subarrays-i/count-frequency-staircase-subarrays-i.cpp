class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> good, cnt;
        int len = 1;
        while(len*(len+1)/2 <= n) {
            good[len*(len+1)/2] = 1;
            cnt[len*(len+1)/2] = len;
            len++;
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            unordered_map<int,int> rank, freq;
            for(int j=i;j<n;j++) {
                if(!rank.count(nums[j])) {
                    int r = rank.size();
                    rank[nums[j]] = r + 1;
                }
                freq[rank[nums[j]]]++;
                if(rank[nums[j]] < freq[rank[nums[j]]]) break;
                if(good.count(j-i+1) && cnt[j-i+1] == (int)rank.size()) ans++;
            }
        }

        return ans;
    }
};