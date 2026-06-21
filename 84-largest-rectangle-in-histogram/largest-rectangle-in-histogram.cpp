class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int largest = 0;

        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int ht = heights[st.top()], nse = i;
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                largest = max(largest, ht * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int ht = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            largest = max(largest, ht * (n - pse - 1));
        }

        return largest;
    }
};