class MinStack {
public:
    vector<int> st;
    vector<int> minimums_stack;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);

        if (minimums_stack.empty() || value <= minimums_stack.back())
            minimums_stack.push_back(value);
    }
    
    void pop() {
        int value = st.back();
        st.pop_back();

        if (value == minimums_stack.back())
            minimums_stack.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minimums_stack.back();
    }
};