class Solution {
public:
    int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n), nsee(n);
        // Find PSE
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Find NSEE
        st = stack<int> ();

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        for(int i=0;i<n;i++) {
            long long left = i - pse[i];
            long long right = nsee[i] - i;
            total += (left * right * arr[i]);
            total %= mod;
        }

        return (int)total;
    }
};