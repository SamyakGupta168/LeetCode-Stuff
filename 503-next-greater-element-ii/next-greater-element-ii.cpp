class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int i = max_element(nums.begin(), nums.end()) - nums.begin();
        vector<int> ans(n);
        ans[i] = -1;
        stack<int> st;
        st.push(nums[i]);
        int idx = i;
        i = (i - 1 + n) % n;
        while(idx != i) {
            if(nums[i] < st.top()) {
                ans[i] = st.top();
            } else {
                while(!st.empty() && nums[i] >= st.top()) {
                    st.pop();
                }
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(nums[i]);
            i = (i - 1 + n) % n;
        }

        return ans;
    }
};