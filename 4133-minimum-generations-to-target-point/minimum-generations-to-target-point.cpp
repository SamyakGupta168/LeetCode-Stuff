class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& tar) {
        for(auto &v : points) {
            if(v == tar) return 0;
        }

        set<vector<int>> st;
        for(auto &v : points) st.insert(v);

        for(int k=1;k<=13;k++) {
            set<vector<int>> temp;
            for(auto it1 = st.begin(); it1 != st.end(); it1++) {
                auto it2 = it1;
                it2++;
                while(it2 != st.end()) {
                    auto &v = *it1;
                    auto &u = *it2;
                    if(u == v) continue;
                    vector<int> c(3);
                    c[0] = (u[0]+v[0])/2;
                    c[1] = (u[1]+v[1])/2;
                    c[2] = (u[2]+v[2])/2;
                    if(c == tar) return k;
                    temp.insert(c);
                    it2++;
                }
            }

            for(auto &v : temp) st.insert(v);
        }

        return -1;
    }
};