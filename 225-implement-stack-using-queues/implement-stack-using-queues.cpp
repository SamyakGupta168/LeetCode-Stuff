class MyStack {
public:
    queue<int> q;
    int currSize = 0;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<currSize;i++) {
            q.push(q.front());
            q.pop();
        }
        currSize++;
    }
    
    int pop() {
        int el = q.front();
        q.pop();
        currSize--;
        return el;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */