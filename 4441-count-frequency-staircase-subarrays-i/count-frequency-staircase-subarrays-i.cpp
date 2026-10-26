class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int sub = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> id,freq;
            int cnt = 1;
            for(int j = i;j<n;j++){
                int num = nums[j];
                if(id.count(num)==0){
                    id[num] = cnt;
                    cnt++;
                }
                freq[num]++;
                bool flag = true;
                for(auto p:id){
                    int n1 = p.first,id1 = p.second;
                    if(id1!=freq[n1]){
                        flag = false;
                        break;
                    }
                }
                if(flag) sub++;
            }
        }
        return sub;
    }
};