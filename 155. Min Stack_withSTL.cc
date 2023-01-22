// Using one stack approach
// TC: O(1)
// SC: O(n)
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // we first push the min value to the stack so that we can recovery it and then we update the min value to val
        if (val <= min) {
            st.push(min);
            min = val;
        }
        //we also push the val to the stack.
        st.push(val);
    }
    
    void pop() {
        // we need to pop the min value and recover it from the stack
        if (st.top() == min) {
            st.pop();
            min = st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
private:
    stack<int> st;
    int min = INT_MAX;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */