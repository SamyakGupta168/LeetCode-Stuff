class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        int sum = 1, i = 1;
        while(i < n) {
            if(rat[i] == rat[i-1]) {
                sum += 1;
                i++;
                continue;
            }

            int peak = 1;
            while(i < n && rat[i] > rat[i-1]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while(i < n && rat[i] < rat[i-1]) {
                sum += down;
                down++;
                i++;
            }

            if(down > peak) sum += down - peak;
        }

        return sum;
    }
};