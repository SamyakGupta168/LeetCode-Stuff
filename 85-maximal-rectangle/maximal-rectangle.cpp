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

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> heights(n, vector<int>(m));
        int largest = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == '0') heights[i][j] = 0;
                else heights[i][j] = 1 + (i-1 >= 0 ? heights[i-1][j] : 0);
            }
            largest = max(largest, largestRectangleArea(heights[i]));
        }

        return largest;
    }
};