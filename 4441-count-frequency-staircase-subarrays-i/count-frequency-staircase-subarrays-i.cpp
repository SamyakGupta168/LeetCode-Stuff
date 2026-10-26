class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> good;
        int len = 1;
        while(len*(len+1)/2 <= n) {
            good[len*(len+1)/2] = 1;
            len++;
        }

        for(int i=0;i<n;i++) {
            unordered_map<int,int> mp;
            vector<int> no;
            for(int j=i;j<n;j++) {
                if(!mp.count(nums[j])) no.push_back(nums[j]);
                mp[nums[j]]++;
                if(good.count(j-i+1)) {
                    int freq = 1;
                    bool flag = 1;
                    for(auto x : no) {
                        if(mp[x] != freq) {
                            flag = 0;
                            break;
                        }
                        freq++;
                    }
                    if(flag) ans++;
                }
            }
        }

        return ans;
    }
};