class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, -1), pse(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int> ();
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int largest = 0;
        for(int i=0;i<n;i++) {
            largest = max(largest, (nse[i] - pse[i] - 1) * heights[i]);
        }

        return largest;
    }
};