class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for(auto x : ast) {
            if(st.empty()) {
                st.push(x);
                continue;
            } else if(st.top() * x > 0) {
                st.push(x);
            } else {
                if(st.top() > 0) {
                    while(!st.empty() && st.top() < abs(x) && st.top() > 0) {
                        st.pop();
                    }
                    if(st.empty() || st.top() < 0) {
                        st.push(x);
                    } else if(!st.empty() && st.top() == abs(x)) {
                        st.pop();
                    }
                } else {
                    st.push(x);
                }
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};