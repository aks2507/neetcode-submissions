class MinStack {
private:
    stack<int> s;
    stack<int> min;
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);

        if (min.empty()) {
            min.push(val);
        } else {
            int tmp = min.top();
            if (tmp <= val) {
                min.push(tmp);
            } else {
                min.push(val);
            }
        }
    }
    
    void pop() {
        s.pop();
        min.pop();
    }
    
    int top() {
        return s.top();
    }   
    
    int getMin() {
        return min.top();
    }
};
