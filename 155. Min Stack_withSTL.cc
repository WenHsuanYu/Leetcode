// Using one stack approach
// TC: O(1)
// SC: O(n)
class MinStack {
public:
    stack<int64_t> st;
    int64_t min;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            min = val;
        } else if (val <= min) {
            //A trick: 2 * val - min = flag
            //2ll instead of
            st.push(2ll * val - min);
            min = val;
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }
        // we restore previous min if we meet flag 
        // Because current min is less than previous, flag is also less than current min 
        if (st.top() < min) {
            // 2 * min - flag = previous min
            //2ll instead of 2
            min = 2ll * min - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.empty())
            return -1;
        if (st.top() < min) {
            return min;
        }
        return st.top();
    }
    
    int getMin() {
        if (st.empty())
            return -1;
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */