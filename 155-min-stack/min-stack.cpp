class MinStack {
public:
    multiset<int> ms;
    stack<int> st;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        ms.insert(value);
    }
    
    void pop() {
        ms.erase(ms.find(st.top()));
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *ms.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */