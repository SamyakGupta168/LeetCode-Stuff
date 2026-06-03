class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m =  waterStartTime.size();
        // Case 1 :- land --> water 
        int ans1 = 1e9;
        for(int i=0;i<n;i++) {  
            if(landStartTime[i] + landDuration[i] < ans1) {
                ans1 = landStartTime[i] + landDuration[i];
            }
        }

        int val = 1e9;
        for(int j=0;j<m;j++) {
            if(waterStartTime[j] >= ans1) {
                val = min(val, waterStartTime[j] - ans1 + waterDuration[j]);
            } else {
                val = min(val, waterDuration[j]);
            }
        }
        ans1+=val;

        // Case 2 :- water --> land
        int ans2 = 1e9;
        for(int i=0;i<m;i++) {  
            if(waterStartTime[i] + waterDuration[i] < ans2) {
                ans2 = waterStartTime[i] + waterDuration[i];
            } 
        }

        val = 1e9;
        for(int j=0;j<n;j++) {
            if(landStartTime[j] >= ans2) {
                val = min(val, landStartTime[j] - ans2 + landDuration[j]);
            } else {
                val = min(val, landDuration[j]);
            }
        }
        ans2+=val;

        return min(ans1, ans2);
    }
};