class Solution {
public:
    int maximumGap(string skill, string stat) {
        int n = skill.size(), m = stat.size();
        vector<int> left(n, -1), right(n, -1);
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(skill[i] == stat[j]) {
                left[i] = j;
                i++;
            }
            j++;
        } 

        i = n-1, j = m-1;
        while(i >= 0 && j >= 0) {
            if(skill[i] == stat[j]) {
                right[i] = j;
                i--;
            } 
            j--;
        }

        int mx = 0;
        for(int i=1;i<n;i++) {
            mx = max(mx, right[i] - left[i-1]);
        }

        return mx;
    }
};