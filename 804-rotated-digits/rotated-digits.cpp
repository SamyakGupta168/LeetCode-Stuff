class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            string temp = to_string(i);
            string temp2;
            bool inValid = false;
            for(int j=0;j<temp.size();j++) {
                if(temp[j]=='3' or temp[j]=='4' or temp[j]=='7') {
                    inValid = true;
                    break;
                }
                if(temp[j]=='0' or temp[j]=='1' or temp[j]=='8') temp2+=temp[j];
                if(temp[j]=='2') temp2[j]+='5';
                if(temp[j]=='6') temp2[j]+='9';
                if(temp[j]=='5') temp2[j]+='2';
                if(temp[j]=='9') temp2[j]+='6';
            }
            if(!inValid && temp!=temp2) cnt++;
        }

        return cnt;
    }
};