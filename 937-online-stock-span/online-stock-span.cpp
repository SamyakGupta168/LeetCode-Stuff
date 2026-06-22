class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int span = st.empty() ? idx + 1 : idx - st.top().second;
        st.push({price, idx});
        idx++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */