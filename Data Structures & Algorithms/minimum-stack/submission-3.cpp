class MinStack {
public:
    stack<int> st;
    stack<int> prefix;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(prefix.empty()) {
            prefix.push(val);
        } else {
            if(prefix.top() < val) {
                prefix.push(prefix.top());
            } else {
                prefix.push(val);
            }
        }
    }
    
    void pop() {
        st.pop();
        prefix.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return prefix.top();
    }
};
