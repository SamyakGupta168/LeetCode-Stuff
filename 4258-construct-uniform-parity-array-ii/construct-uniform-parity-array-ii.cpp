class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool ans1 = true, ans2 = true;

        int mn = INT_MAX;
        for(int x : nums1) {
            if(x&1) mn = min(mn, x);
        }

        // All even
        for(int i=0;i<n;i++) {
            if(nums1[i]%2==0) continue;
            else {
                if(mn==INT_MAX || mn>=nums1[i]) {
                    ans1 = false;
                    break;
                }
            }
        }

        // All odd
        for(int i=0;i<n;i++) {
            if(nums1[i]&1) continue;
            else {
                if(mn==INT_MAX || mn>=nums1[i]) {
                    ans2 = false;
                    break;
                }
            }
        }

        return (ans1|ans2);
    }
};