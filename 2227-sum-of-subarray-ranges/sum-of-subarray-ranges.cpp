class Solution {
public:
    using ll = long long;

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        // Finding the maximum
        vector<int> pge(n), ngee(n);
        // Find PGE
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Find NGEE
        st = stack<int> ();

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            ngee[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalMax = 0;
        for(int i=0;i<n;i++) {
            long long left = i - pge[i];
            long long right = ngee[i] - i;
            totalMax += (left * right * nums[i]);
        }


        // Finding the minimum 
        vector<int> pse(n), nsee(n);
        // Find PSE
        st = stack<int> ();
        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Find NSEE
        st = stack<int> ();

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalMin = 0;
        for(int i=0;i<n;i++) {
            long long left = i - pse[i];
            long long right = nsee[i] - i;
            totalMin += (left * right * nums[i]);
        }

        return totalMax - totalMin;
    }
};