class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1);
	    for(int i=0;i<n;i++) {
		    for(int j=0;j<i;j++) {
			    if(nums[i] > nums[j]) dp1[i] = max(dp1[i], 1 + dp1[j]);
		    }
	    }

	    vector<int> temp = nums;
	    reverse(temp.begin(), temp.end());
	    vector<int> dp2(n, 1);
	    for(int i=0;i<n;i++) {
		    for(int j=0;j<i;j++) {
			    if(temp[i] > temp[j]) dp2[i] = max(dp2[i], 1 + dp2[j]);
		    }
    	}
	    reverse(dp2.begin(), dp2.end());

	    int ans = 0;
	    for(int i=0;i<n;i++) {
	        if(dp1[i] > 1 && dp2[i] > 1) ans = max(ans, dp1[i] + dp2[i] - 1);
	    }

	    return n - ans;
    }
};