class MyStack {
public:
    queue<int> q;

    void goToLastElement() {
        for (size_t i = 0; i <= q.size() - 2; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if (q.size() == 1) {
            int val = q.front();
            q.pop();
            return val;
        } else if (q.size() == 2) {
            q.push(q.front());
            q.pop();
            int val = q.front();
            q.pop();
            return val;
        } else {
            goToLastElement();
            int val = q.front();
            q.pop();
            return val;
        }
    }
    
    int top() {
        if (q.size() == 1) return q.front();
        else if (q.size() == 2) {
            q.push(q.front());
            q.pop();
            int val = q.front();
            q.push(q.front());
            q.pop();
            return val;
        } else {
            goToLastElement();
            int val = q.front();
            q.push(q.front());
            q.pop();
            return val;
        }
    }
    
    bool empty() {
        return q.size() == 0;
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