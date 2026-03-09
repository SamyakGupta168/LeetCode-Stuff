class Solution {
public:
    string bin(int x, int n) {
        string temp;
        while(x>0) {
            if(x&1) temp = "1" + temp;
            else temp = "0" + temp;
            x/=2;
        }
        while(temp.size()<n) temp = "0" + temp;
        return temp;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(int i=0;i<n+2;i++) {
            string temp = bin(i, n);
            bool exist = false;
            for(int i=0;i<n;i++) {
                if(nums[i]==temp) {
                    exist = true;
                    break;
                }
            }
            if(!exist) return temp;
        }
        return "";
    }
};